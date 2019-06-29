/**
 * Project Game
 */


#ifndef _MELEEENEMY_H
#define _MELEEENEMY_H

#include "GameCharacter.h"
#include "Enemy.h"


class MeleeEnemy: public Enemy {
public:
    MeleeEnemy(const float &x, const float &y, const float &str = DEF_ENEMY_STRENGTH, const bool &par = false,
               const bool &onf = false,
               const float &h = DEF_ENEMY_HEALTH, const bool &facingR = true, const float &s = ENEMY_SPEED);

    //default constructor
    MeleeEnemy();

    //copy constructor
    MeleeEnemy(const MeleeEnemy& copied);

    ~MeleeEnemy() {};

    MeleeEnemy& operator = (const MeleeEnemy& meleeEnemy);

    void move(const Direction& direction, const float& distance);

protected:
    void initSprite(const float &x, const float &y);
    void giveHitbox();
};

#endif //_MELEEENEMY_H