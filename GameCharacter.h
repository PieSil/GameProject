/**
 * Project Game
 */


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

#include "MovingEntity.h"
#include "AttackBehaviour.h"
#include "MeleeBehaviour.h"
#include "ShootingBehaviour.h"

struct Clocks {
    sf::Clock attackClock;
    sf::Clock burnClock;
    sf::Clock paralyzedClock;
    sf::Clock abilityClock;
    sf::Clock damagedClock;
    sf::Clock invincibilityClock;
    sf::Clock manaClock;
};

class GameCharacter : public MovingEntity {
public: 

    GameCharacter(const float &x, const float &y, const float &str = 5., const bool &onf = false, const float &h = 10,
                  const float &s = 1., const bool &facingR = true, const float& attackRange = 16);

    //default constructor
    GameCharacter();

    //copy constructor
    GameCharacter(const GameCharacter &copied);

    ~GameCharacter() = 0;

    const EntityPositions move(const Direction &direction, const float &distance) override;

    void jump();

    virtual const std::pair<bool, Hitbox> attack(const bool &bypassClock = false); //BYPASS CLOCK USED FOR UNIT TESTING

    virtual const bool getDamaged(const float &damage);

    void animate() override;

    void setupAnimations(const SpriteParams *parameters) override;

    virtual void updateStatus();

    virtual void checkIfOnFire();

    const bool isAttacking();

    const bool isDying();;

    virtual void setAttackBehaviour(std::shared_ptr<AttackBehaviour> attackBehaviourPtr) {
        this->attackBehaviour = std::move(attackBehaviourPtr);
    }

    //HELPER METHODS
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

    float getAttackRange() const {
        return attackRange;
    }

    Clocks &getClocks() { //not const to allow projectiles to modify clocks
        return clocks;
    }

protected:
    bool onFire;
    float health;
    float strength;
    float attackRange;
    float attackTimeStep;

    Clocks clocks;

    std::shared_ptr<AttackBehaviour> attackBehaviour;

};

#endif //_GAMECHARACTER_H