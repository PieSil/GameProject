/**
 * Project Game
 */


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include "MovingEntity.h"
#include "AttackBehaviour.h"

class GameCharacter : public MovingEntity {
public: 

    GameCharacter(const float &x, const float &y, const float &str = 5., const bool &onf = false, const float &h = 10,
                  const float &s = 1., const bool &facingR = true);

    //default constructor
    GameCharacter();

    //copy constructor
    GameCharacter(const GameCharacter &copied);

    ~GameCharacter() = 0;

    const entityPositions move(const Direction &direction, const float &distance) override;

    virtual void attack();

    void setupAnimations(const SpriteParams *parameters) override;

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

    void setAttackBehaviour(AttackBehaviour* attackBehaviour) {
        GameCharacter::attackBehaviour.reset(attackBehaviour);
    }

    void animate() override;

protected:
    bool onFire;
    float health;
    float strength;
    std::unique_ptr<AttackBehaviour> attackBehaviour;

};

#endif //_GAMECHARACTER_H