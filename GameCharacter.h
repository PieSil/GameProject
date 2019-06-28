/**
 * Project Game
 */


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include "GameEntity.h"

class GameCharacter : public GameEntity {
public: 

    GameCharacter(const float &x, const float &y, const float &str = 5., const bool &onf = false, const float &h = 10,
                  const float &s = 1., const bool &facingR = true);

    //default constructor
    GameCharacter();

    //copy constructor
    GameCharacter(GameCharacter &copied);

    ~GameCharacter() = 0;

    virtual void attack();

    virtual void jump(const float &height);

    float getHealth() const {
        return health;
    }

    void setHealth(float health) {
        GameCharacter::health = health;
    }

    bool isOnFire() const {
        return onFire;
    }

    void setOnFire(bool onFire) {
        GameCharacter::onFire = onFire;
    }

    float getStrength() const {
        return strength;
    }

    void setStrength(float strength) {
        GameCharacter::strength = strength;
    }

    bool isOnGround() const {
        return onGround;
    }

    void setOnGround(bool onGround) {
        GameCharacter::onGround = onGround;
    }

    float getVelocityY() const {
        return velocityY;
    }

    void setVelocityY(float velocityY) {
        GameCharacter::velocityY = velocityY;
    }

protected:
    bool onFire;
    float health;
    float strength;

    //used for jumping
    bool onGround;
    float velocityY;
};

#endif //_GAMECHARACTER_H