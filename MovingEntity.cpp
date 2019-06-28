//
// Created by Pietro on 2019-06-28.
//

#include "GameEntity.h"
#include "GameCharacter.h"
#include "math.h"
#include "MovingEntity.h"



MovingEntity::MovingEntity(const float& x, const float& y, const float &movSpeed, const bool &facingR)
                          : GameEntity(x,y),
                            movementSpeed(movSpeed), facingRight(facingR), movingCounter(0), onGround(false), velocityY(0) {

}



MovingEntity::MovingEntity(const MovingEntity &copied) : GameEntity(copied), movementSpeed(copied.getMovementSpeed()), facingRight(copied.isFacingRight()),
movingCounter(0), onGround(copied.isOnGround()), velocityY(copied.getVelocityY()){

}



void MovingEntity::moveOnX(const Direction &direction, const float &distance, const int &width, const int &height,
                         const float &scale, const int &row, const int &lastColumn) {

    //MOVE ON X AXIS

    if (direction == RIGHT) {

        sprite.move(distance, 0.); //move right


        sprite.setTextureRect(sf::IntRect(width * static_cast<int>(movingCounter), width * row, width,
                                          height)); //update sprite animation


        if (!(facingRight)) { //flip horizontally
            sprite.setScale(scale * 1.f, scale * 1.f);
            facingRight = true;
        }

    } else if (direction == LEFT) {

        sprite.move(-distance, 0.); //move left


        sprite.setTextureRect(sf::IntRect(width * static_cast<int>(movingCounter), width * row, width,
                                          height)); //update sprite animation


        if (facingRight) { //flip horizontally
            sprite.setScale(-(scale * 1.f), scale * 1.f);
            facingRight = false;

        } else {
            //TODO: throw exception

        }

    }

        //moves hitbox with sprite
        hitbox.setPosition(sprite.getPosition());

        //update movingCounter
        movingCounter += ANIM_COUNT_INCR;

        if (movingCounter > lastColumn) {
            movingCounter = 0;
        }
}

void MovingEntity::moveOnY(const float &height, const Direction &direction) {

    //MOVE ON Y AXIS

    if (direction == UP) { //move upwards
        sprite.move(0, -height);

    } else if (direction == DOWN) {
        sprite.move(0, height); //move downwards


    } else {

        //TODO: throw exception
    }

    hitbox.setPosition(sprite.getPosition());
}

void
MovingEntity::initSprite(const float &x, const float &y, const std::string &path, const int &width, const int &height,
                         const float &scale, const int &row, const int &column) {
    GameEntity::initSprite(x, y, path, width, height, scale, row, column);

    if (MovingEntity::facingRight) {
        sprite.setScale(scale * 1.f, scale * 1.f);
    } else {
        sprite.setScale(-scale * 1.f, scale * 1.f);
    }
}
