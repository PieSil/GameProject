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
        onFire(onf), health(abs(h)), strength(abs(str)), attackRange(attackRange), attackTimeStep(HERO_ATT_TIMESTEP),
        MovingEntity(x, y, s, facingR) {
}

GameCharacter::~GameCharacter() {};


const std::pair<bool, Hitbox> GameCharacter::attack(const bool &bypassClock) {

    std::pair<bool, Hitbox> result;

    if ((attackClock.getElapsedTime().asSeconds() >= attackTimeStep) || bypassClock) {
        attackClock.restart();
        result = attackBehaviour->attack(state, allPositions, attackRange);
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
    }

    MovingEntity::animate();
}

const EntityPositions GameCharacter::move(const Direction &direction, const float &distance) {
    if (state != EntityState::MELEE && state != EntityState::SHOOTING) //enable movement only if not attacking
       return(MovingEntity::move(direction, distance));

    else
        return allPositions;
}

void GameCharacter::getDamaged(const float &damage) {
    health -= damage;

    if (health <= 0) {
        //TODO: set state to dying
        std::cout << "DEAD" << std::endl;
    }
}
