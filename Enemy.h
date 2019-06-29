/**
 * Project Game
 */


#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameCharacter.h"


class Enemy: public virtual GameCharacter {

public:

    Enemy(const float &x, const float &y, const float &str = DEF_ENEMY_STRENGTH, const bool &par = false,
          const bool &onf = false,
          const float &h = DEF_ENEMY_HEALTH, const bool &facingR = true, const float &s = ENEMY_SPEED);

    //defaut constructor
    Enemy();

    //copy constructor
    Enemy(const Enemy& copied);

    virtual ~Enemy() = 0;

    //override attack and move methods to check if enemy is paralyzed

    void attack() override;

    void moveOnX(const Direction &direction, const float &distance, const int &width, const int &height, const float &scale,
                 const int &row, const int &lastColumn) override;

    void moveOnY(const float &height, const Direction &direction) override;

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

protected: 
    bool paralyzed;
    bool aggro;
};

#endif //_ENEMY_H