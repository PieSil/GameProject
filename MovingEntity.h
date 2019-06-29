//
// Created by Pietro on 2019-06-28.
//

#ifndef GAMEPROJECT_MOVINGENTITY_H
#define GAMEPROJECT_MOVINGENTITY_H

#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "gameValues.h"
#include "Hitbox.h"

class MovingEntity : public GameEntity {
public:
    MovingEntity(const float& x, const float&y, const float& movSpeed = 100, const bool& facingR = true);

    //copy constructor
    MovingEntity(const MovingEntity &copied);

    //default constructor
    MovingEntity();

    virtual ~MovingEntity() {};

    void animate(float &animCounter, const int &width, const int &height, const float &scale, const int &row,
                 const int &lastColumn) override;

    float getMovementSpeed() const {
        return movementSpeed;
    }

    bool isFacingRight() const {
        return facingRight;
    }

    int getMovingCounter() const {
        return movingCounter;
    }

    bool isOnGround() const {
        return onGround;
    }

    void setOnGround(bool onGround) {
        MovingEntity::onGround = onGround;
    }

    float getVelocityY() const {
        return velocityY;
    }

    void setVelocityY(float velocityY) {
        MovingEntity::velocityY = velocityY;
    }

    virtual void
    move(const Direction &direction, const float &distance);

    virtual void moveOnY(const float &height, const Direction &direction);

protected:

    void initSprite(const float &x, const float &y, const std::string &path, const int &width, const int &height,
                    const float &scale, const int &row, const int &column) override;

    float movementSpeed;


    //boolean value used to determine if the character is facing right or left
    bool facingRight;

    //counter used to update sprite in order to generate walking/moving animation
    float movingCounter;

    //used for jumping and falling
    bool onGround;
    float velocityY;

};


#endif //GAMEPROJECT_MOVINGENTITY_H
