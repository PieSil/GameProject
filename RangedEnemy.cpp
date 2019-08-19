/**
 * Project Game
 */


#include "RangedEnemy.h"
#include "Enemy.h"

/**
 * RangedEnemy implementation
 */

const SpriteParams RangedEnemy::rangedParams(RANGED_PATH, RANGED_WIDTH, RANGED_HEIGHT, RANGED_SCALE, RANGED_HITBOX_X,
                                             RANGED_HITBOX_Y, RANGED_IDLE_ROW, RANGED_IDLE_LAST_COL, RANGED_MOV_ROW,
                                             RANGED_MOV_LAST_COL, RANGED_ATT_ROW, RANGED_ATT_LAST_COL,
                                             RANGED_ATT_OFFSET, RANGED_SHOOT_ROW, RANGED_SHOOT_LAST_COL,
                                             RANGED_DEATH_ROW, RANGED_DEATH_LAST_COL);

RangedEnemy::RangedEnemy(GameHero *hero, const float &x, const float &y, const float &str, const bool &par,
                         const bool &onf, const float &h, const bool &facingR, const float &s) :
        Enemy(hero, x, y, str, par, onf, h, facingR, s) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());
    attackRange = RANGED_ATTACK_RANGE;
    attackTimeStep = RANGED_ATT_TIMESTEP;
    setAttackBehaviour(std::make_shared<ShootingBehaviour>());
}

RangedEnemy::RangedEnemy(const RangedEnemy &copied) : Enemy(copied) {
    this->aggro = false;
    this->paralyzed = false;
}

RangedEnemy &RangedEnemy::operator=(const RangedEnemy &rangedEnemy) {
    this->hero = rangedEnemy.getHero();
    this->aggro = false;
    this->paralyzed = false;
    return *this;
}

const EntityPositions RangedEnemy::move(const float &distance) {
    EntityPositions prevPosition;

    updateAggro();

    prevPosition = allPositions;

    if (!paralyzed && aggro) { //if enemy is not paralyzed and aggro is active

        if (facingRight) { //if enemy is facing right
            prevPosition = GameCharacter::move(Direction::RIGHT, distance); //move right

        } else {
            prevPosition = GameCharacter::move(Direction::LEFT, distance); //else move left
        }

    }

    return prevPosition;
}

void RangedEnemy::updateAggro() {

    if (state != EntityState::DYING && state != EntityState::DEAD) {

        //if aggro is not activated and hero sprite is in aggro range
        // (if absolute value of hero x coordinate - enemy x coordinate is < aggro range then hero is in aggro range)
        if (!aggro && abs(hero->getSprite().getPosition().x - this->sprite.getPosition().x) <= aggroRange &&
            heroIsInRange()) {
            aggro = true; //activate aggro
        }

        //ranged enemy behaves the opposite of other enemies, it will not chase the player but will run from it

        if (hero->getSprite().getPosition().x <=
            this->sprite.getPosition().x) { //if hero is at enemy's left (hero x coordinate is < sprite x coordinate)
            facingRight = true; //turn right

        } else {
            facingRight = false; //else turn left
        }
    }
}


const std::pair<bool, Hitbox> RangedEnemy::attack(const bool &bypassClock) {

    std::pair<bool, Hitbox> attackResult = Enemy::attack(bypassClock);

    if (attackResult.first) {
        if (hero->getSprite().getPosition().x <=
            this->sprite.getPosition().x) { //if hero is at enemy's left (hero x coordinate is < sprite x coordinate)
            facingRight = false; //turn left

        } else {
            facingRight = true; //else turn right
        }
    }

    return attackResult;

}

