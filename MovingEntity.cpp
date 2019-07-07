//
// Created by Pietro on 2019-06-28.
//

#include "GameEntity.h"
#include "GameCharacter.h"
#include "math.h"
#include "MovingEntity.h"


MovingEntity::MovingEntity(const float &x, const float &y, const float &movSpeed, const bool &facingR)
        : GameEntity(x, y),
          movementSpeed(movSpeed), facingRight(facingR), movingCounter(0), onGround(false), velocityY(0) {
}


MovingEntity::MovingEntity(const MovingEntity &copied) : GameEntity(copied), movementSpeed(copied.getMovementSpeed()),
                                                         facingRight(copied.isFacingRight()),
                                                         movingCounter(0), onGround(copied.isOnGround()),
                                                         velocityY(copied.getVelocityY()) {

}


const entityPositions MovingEntity::move(const Direction &direction, const float &distance) {

    entityPositions prevPosition = allPositions;

    //MOVE ON X AXIS

    if (direction == RIGHT) {

        sprite.move(distance, 0.); //move right

        state = WALKING;

        if (!(facingRight)) {
            facingRight = true; //change facing direction
        }


    } else if (direction == LEFT) {

        sprite.move(-distance, 0.); //move left

        state = WALKING;

        if (facingRight) {
            facingRight = false; //change facing direction
        }

        //MOVE ON Y AXIS

    } else if (direction == UP) { //move upwards
        sprite.move(0, -distance);

    } else if (direction == DOWN) {
        sprite.move(0, distance); //move downwards

    } else {

        //TODO: throw exception
    }

    //moves hitbox with sprite
    hitbox.setPosition(sprite.getPosition());
    updatePositions();

    return prevPosition;

}

void
MovingEntity::initSprite(const float &x, const float &y) {
    GameEntity::initSprite(x, y);

    if (MovingEntity::facingRight) {
        sprite.setScale(getParameters()->scale, getParameters()->scale);
    } else {
        sprite.setScale(-getParameters()->scale, getParameters()->scale);
    }
}

MovingEntity::MovingEntity() : MovingEntity(0, 0) {

}

void MovingEntity::setupAnimations(const SpriteParams *parameters) {
    GameEntity::setupAnimations(parameters); //create animation manager and IDLE animation (see GameEntity method)
    animManager.createAnimation(WALKING); //create walking animation
}

void MovingEntity::animate() {
    animManager.play(state, facingRight); //play animation based on current state and facing direction
}

void MovingEntity::updatePositions() {
    allPositions.spritePosition = sprite.getPosition();

    allPositions.hitboxPosition = hitbox.getHitbox().getPosition();
    allPositions.upperEdgePosition = hitbox.getUpperEdge().getPosition();
    allPositions.lowerEdgePosition = hitbox.getLowerEdge().getPosition();
    allPositions.leftEdgePosition = hitbox.getLeftEdge().getPosition();
    allPositions.rightEdgePosition = hitbox.getRightEdge().getPosition();

}


