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
                             const float &s, const bool &facingR) :
        onFire(onf), health(abs(h)), strength(abs(str)),
        MovingEntity(x, y, s, facingR) {

}

GameCharacter::~GameCharacter() {};


const float &GameCharacter::attack() {

    if (state != ATTACKING) {//if character is not attacking


        state = ATTACKING; //enter attacking state
    }

    return strength;

}

GameCharacter::GameCharacter() : GameCharacter(0, 0) {

}

GameCharacter::GameCharacter(const GameCharacter &copied) : health(copied.getHealth()), onFire(copied.isOnFire()),
                                                            strength(copied.getStrength()), MovingEntity(copied) {

}

void GameCharacter::setupAnimations(const SpriteParams *parameters) {
    MovingEntity::setupAnimations(parameters);
    animManager.createAnimation(ATTACKING); //create attack animation
}

void GameCharacter::animate() {

    if (state == ATTACKING) {
        if (animManager.getCurrentFrame(ATTACKING) == getParameters()->attLastCol) { //if animation is on last frame
            animManager.resetAnimation(ATTACKING); //reset animation to the beginning
            state = IDLE; //reset state to idle to avoid looping the animation
        }

    }

    MovingEntity::animate();
}

const entityPositions GameCharacter::move(const Direction &direction, const float &distance) {

    if (state != ATTACKING) //enable movement only if not attacking
       return(MovingEntity::move(direction, distance));

    else
        return allPositions;
}
