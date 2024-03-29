/**
 * Project Game
 */


#include "RangedEnemy.h"
#include "Enemy.h"

/**
 * Enemy implementation
 */
Enemy::Enemy(GameHero *hero, const float &x, const float &y, const float &str, const bool &par, const bool &onf,
             const float &h, const bool &facingR, const float &s)
        : hero(hero), paralyzed(par), aggro(false), aggroRange(DEF_ENEMY_AGGRO_RANGE), GameCharacter(x, y, str, onf, h, s, facingR) {

}

Enemy::Enemy(const Enemy &copied) : hero(copied.getHero()), paralyzed(false), aggro(false),
                                    aggroRange(copied.getAggroRange()), GameCharacter(copied) {
    setupAudio();

}

const std::pair<bool, Hitbox> Enemy::attack(const bool &bypassClock) {

    std::pair<bool, Hitbox> result;

    result.first = false;

    if (!paralyzed && heroIsInFront())
        result = GameCharacter::attack();

    return  result;
}

const EntityPositions Enemy::move(const float &distance) {

    EntityPositions prevPosition;

    updateAggro();

    prevPosition = allPositions;

    if (!paralyzed && aggro && !isAttacking() && !isDying()) { //if enemy is not paralyzed and aggro is active

        if (abs(hero->getSprite().getPosition().x - sprite.getPosition().x) >= attackRange) {

            if (facingRight) { //if enemy is facing right
                prevPosition = GameCharacter::move(Direction::RIGHT, distance); //move right

            } else {
                prevPosition = GameCharacter::move(Direction::LEFT, distance); //else move left
            }
        } else {
            state = EntityState::IDLE;
        }

    }

    return prevPosition;

}

void Enemy::updateAggro() {

    if (!isDying()) {

        //if aggro is not activated and hero sprite is in aggro range
        // (if absolute value of hero x coordinate - enemy x coordinate is < aggro range then hero is in aggro range)
        if (!aggro && abs(hero->getSprite().getPosition().x - this->sprite.getPosition().x) <= aggroRange) {
            aggro = true; //activate aggro
        }

        if (hero->getSprite().getPosition().x <=
            this->sprite.getPosition().x) { //if hero is at enemy's left (hero x coordinate is < sprite x coordinate)
            facingRight = false; //turn left

        } else {
            facingRight = true; //else turn right
        }
    }
}

const std::pair<bool, Hitbox> Enemy::updateCombat() {
    updateAggro();
    return attack();
}

void Enemy::updateStatus() {
    GameCharacter::updateStatus();

    if (paralyzed) {
        
        if (clocks.paralyzedClock.getElapsedTime().asSeconds() >= PARALYSIS_DURATION)
            paralyzed = false;
    }

}

void Enemy::checkIfOnFire() {
    if (onFire && clocks.damagedClock.getElapsedTime().asSeconds() >= BURN_DAMAGE_TIMESTEP) { //if character is on fire and has not been damaged in set amount of time
        getDamaged(ENEMY_BURN_DAMAGE);  //take damage

        if (clocks.burnClock.getElapsedTime().asSeconds() >= BURN_DURATION) { //if enough time has passed
            onFire = false; //set on fire to off
        }
    }
}


void Enemy::animate() {
    if(!paralyzed)
        GameCharacter::animate();

    else {
        if (state == EntityState::MELEE) {
            if (animManager.getCurrentFrame(EntityState::MELEE) == getParameters()->attLastCol) { //if animation is on last frame
                animManager.resetAnimation(EntityState::MELEE); //reset animation to the beginning
                state = EntityState::IDLE; //reset state to idle to avoid looping the animation
            }

        } else if (state == EntityState::SHOOTING) {
            if (animManager.getCurrentFrame(EntityState::SHOOTING) == getParameters()->shootLastCol) { //if animation is on last frame
                animManager.resetAnimation(EntityState::SHOOTING); //reset animation to the beginning
                state = EntityState::IDLE; //reset state to idle to avoid looping the animation
            }

        } else if (state == EntityState::DYING) {
            if (animManager.getCurrentFrame(EntityState::DYING) == getParameters()->deathLastCol) { //if animation is on last frame
                state = EntityState::DEAD;
            }
        }

        animManager.checkAnimState();
    }

}

const bool Enemy::heroIsInFront() {

    bool inRange = false;

    if (abs(hero->getSprite().getPosition().y - this->sprite.getPosition().y) <= hero->getSprite().getGlobalBounds().height/2.) {
        inRange = true;
    }

    return inRange;
}

void Enemy::setupAudio() {
    GameEntity::setupAudio();
    audioPlayer.insertSound(SoundID::HIT, HIT_SOUND_PATH, ENEMY_HIT_PITCH, DEF_SFX_VOLUME);
}
