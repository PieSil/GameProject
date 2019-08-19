/**
 * Project Game
 */


#ifndef _RANGEDENEMY_H
#define _RANGEDENEMY_H

#include "GameCharacter.h"
#include "Enemy.h"


class RangedEnemy: public Enemy {

public:
    RangedEnemy(GameHero *hero, const float &x, const float &y, const float &str = DEF_RANGED_STRENGTH,
    const bool &par = false, const bool &onf = false, const float &h = DEF_RANGED_HEALTH,
    const bool &facingR = true, const float &s = RANGED_SPEED);

    RangedEnemy(const RangedEnemy& copied);

    RangedEnemy& operator = (const RangedEnemy& rangedEnemy);

    ~RangedEnemy() = default;

    const EntityPositions move(const float &distance) override;

    void updateAggro() override;

    const std::pair<bool, Hitbox> attack(const bool &bypassClock) override;

    const SpriteParams *getParameters() const override {
        return &rangedParams;
    }

protected:
    static const SpriteParams rangedParams;

};

#endif //_RANGEDENEMY_H