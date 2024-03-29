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
    MeleeEnemy(GameHero *hero, const float &x, const float &y, const float &str = DEF_MELEE_STRENGTH,
               const bool &par = false, const bool &onf = false, const float &h = DEF_MELEE_HEALTH,
               const bool &facingR = true, const float &s = ENEMY_SPEED);

    //copy constructor
    MeleeEnemy(const MeleeEnemy& copied);

    ~MeleeEnemy() {};

    const std::pair<bool, Hitbox> attack(const bool &bypassClock) override;

    MeleeEnemy& operator = (const MeleeEnemy& meleeEnemy);

    const SpriteParams *getParameters() const override {
        return &meleeParams; //overrides getParameters to return a pointer to meleeParams instead of entityParams
    }

    void setupAudio() override;

protected:

    static const SpriteParams meleeParams;
};

#endif //_MELEEENEMY_H