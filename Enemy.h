/**
 * Project Game
 */


#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameCharacter.h"
#include "SpriteObserver.h"


class Enemy: public virtual GameCharacter {

public:

    Enemy(const float &x, const float &y, const float &str = DEF_ENEMY_STRENGTH, const bool &par = false,
          const bool &onf = false,
          const float &h = DEF_ENEMY_HEALTH, const bool &facingR = true, const float &s = ENEMY_SPEED);

    //copy constructor
    Enemy(const Enemy& copied);

    virtual ~Enemy() = 0;

    //override attack and move methods to check if enemy is paralyzed

    void attack() override;

    void move(const Direction &direction, const float &distance) override;

    bool isParalyzed() const {
        return paralyzed;
    }

    void setParalyzed(bool paralyzed) {
        Enemy::paralyzed = paralyzed;
    }

    bool isAggro() const {
        return aggro;
    }

    void setAggro(bool aggro) {
        Enemy::aggro = aggro;
    }

    float getAggroRange() const {
        return aggroRange;
    }

protected: 
    bool paralyzed;
    bool aggro;
    float aggroRange;

};

#endif //_ENEMY_H