/**
 * Project Game
 */


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include "GameEntity.h"

class GameCharacter : public GameEntity {
public: 

    GameCharacter(float x, float y, bool onf = false, float h = 10, float s = 1., bool facingR = true);
    ~GameCharacter() {};

    virtual void attack();

    virtual void jump();

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

protected:
    bool onFire;
    float health;
};

#endif //_GAMECHARACTER_H