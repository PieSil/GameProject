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


void MovingEntity::move(const Direction &direction, const float &distance) {

    //MOVE ON X AXIS

    if (direction == RIGHT) {

        sprite.move(distance, 0.); //move right

        animate(movingCounter, getParameters()->movRow, getParameters()->movLastCol); //animate sprite

        if (!(facingRight)) {
            facingRight = true; //change facing direction
        }


    } else if (direction == LEFT) {

        sprite.move(-distance, 0.); //move left

        animate(movingCounter, getParameters()->movRow, getParameters()->movLastCol); //animate sprite


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

void MovingEntity::animate(float &animCounter, const int &row, const int &lastColumn) {

    GameEntity::animate(animCounter, row, lastColumn);

    //flip horizontally based on facing direction
    if (facingRight)
        sprite.setScale(getParameters()->scale, getParameters()->scale);
    else
        sprite.setScale(-getParameters()->scale, getParameters()->scale);

}
