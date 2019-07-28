/**
 * Project Game
 */


#ifndef _HEART_H
#define _HEART_H

#include "Collectible.h"
#include "GameHero.h"
#include "gameValues.h"

class Heart: public Collectible {
public:
    Heart(const float &x, const float &y, GameHero *hero, const float &heal = DEF_HERO_HEALTH);

    ~Heart() override;

    void characterCollision(GameCharacter *character) override;

protected:
    float heal = DEF_HERO_HEALTH;
};

#endif //_HEART_H