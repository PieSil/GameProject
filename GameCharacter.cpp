/**
 * Project Game
 */


#include "GameCharacter.h"
#include "GameEntity.h"
#include "math.h"

/**
 * GameCharacter implementation
 */


GameCharacter::GameCharacter(const float &x, const float &y, const float &str, const bool &onf, const float &h,
                             const float &s, const bool &facingR, const float& attackRange) :
        onFire(onf), health(abs(h)), strength(abs(str)), attackRange(attackRange),
        MovingEntity(x, y, s, facingR) {
}

GameCharacter::~GameCharacter() {};


const std::pair<bool, Hitbox> GameCharacter::attack(const bool &bypassClock) {

    std::pair<bool, Hitbox> result;
    result.first = false;

    if (state != EntityState::DYING && state != EntityState::DEAD) {

        if ((attackClock.getElapsedTime().asSeconds() >= 1) || bypassClock) {
            attackClock.restart();
            result = attackBehaviour->attack(state, allPositions, attackRange);
        }
    }

    return result;
}

GameCharacter::GameCharacter() : GameCharacter(0, 0) {

}

GameCharacter::GameCharacter(const GameCharacter &copied) : health(copied.getHealth()), onFire(copied.isOnFire()),
                                                            strength(copied.getStrength()), MovingEntity(copied) {

}

void GameCharacter::setupAnimations(const SpriteParams *parameters) {
    MovingEntity::setupAnimations(parameters);
    animManager.createAnimation(EntityState::MELEE); //create attack animation
    animManager.createAnimation(EntityState::SHOOTING); //create shoot animation
    animManager.createAnimation(EntityState::DYING); //create death animation
    animManager.createAnimation(EntityState::DEAD);
}

void GameCharacter::animate() {

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

    MovingEntity::animate();
}

const EntityPositions GameCharacter::move(const Direction &direction, const float &distance) {
    if (state != EntityState::MELEE && state != EntityState::SHOOTING && state != EntityState::DYING && state != EntityState::DEAD) //enable movement only if not attacking
       return(MovingEntity::move(direction, distance));

    else
        return allPositions;
}

void GameCharacter::getDamaged(const float &damage) {

    if (health > 0 && state != EntityState::DYING && state != EntityState::DEAD) {

        health -= damage;

        if (health <= 0) {
            //TODO: set state to dying
            state = EntityState::DYING;
        }
    }
}

void GameCharacter::jump() {
    if(state != EntityState::MELEE && state != EntityState::SHOOTING && state != EntityState::DYING && state != EntityState::DEAD) {
        onGround = false;
        velocityY = JUMP_VELOCITY;
    }
}
