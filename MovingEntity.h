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

    MovingEntity(const MovingEntity &copied);

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
    moveOnX(const Direction &direction, const float &distance, const int &width, const int &height, const float &scale,
            const int &row, const int &lastColumn);

    virtual void moveOnY(const float &height, const Direction &direction);

protected:

    void initSprite(const float &x, const float &y, const std::string &path, const int &width, const int &height,
                    const float &scale, const int &row, const int &column) override;

    float movementSpeed;
    bool facingRight;
    float movingCounter;
    //used for jumping and falling
        bool onGround;
    float velocityY;

};


#endif //GAMEPROJECT_MOVINGENTITY_H
