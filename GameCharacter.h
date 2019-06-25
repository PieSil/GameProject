/**
 * Project Game
 */


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include "GameEntity.h"

class GameCharacter : public GameEntity {
public: 

    GameCharacter(float x, float y, float str = 5., bool onf = false, float h = 10, float s = 1., bool facingR = true);

    //default constructor
    GameCharacter();

    //copy constructor
    GameCharacter(const GameCharacter &copied);

    ~GameCharacter() = 0;

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

    float getStrength() const {
        return strength;
    }

    void setStrength(float strength) {
        GameCharacter::strength = strength;
    }

protected:
    bool onFire;
    float health;
    float strength;
};

#endif //_GAMECHARACTER_H