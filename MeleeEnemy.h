/**
 * Project Game
 */


#ifndef _MELEEENEMY_H
#define _MELEEENEMY_H

#include "GameCharacter.h"
#include "Enemy.h"
#include "MeleeBehaviour.h"


class MeleeEnemy: public Enemy {
public:
    MeleeEnemy(GameHero *hero, const float &x, const float &y, const float &str = DEF_ENEMY_STRENGTH,
               const bool &par = false, const bool &onf = false, const float &h = DEF_ENEMY_HEALTH,
               const bool &facingR = true, const float &s = ENEMY_SPEED);

    //copy constructor
    MeleeEnemy(const MeleeEnemy& copied);

    ~MeleeEnemy() {};

    void attack() override;

    MeleeEnemy& operator = (const MeleeEnemy& meleeEnemy);

    const SpriteParams *getParameters() const override {
        return &meleeParams; //overrides getParameters to return a pointer to meleeParams instead of entityParams
    }

protected:

    static const SpriteParams meleeParams;
};

#endif //_MELEEENEMY_H