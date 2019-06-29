/**
 * Project Game
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "GameHero.h"


class Knight: public GameHero {
public:
    Knight(const float &x, const float &y, const float &str = DEF_GAMEHERO_STRENGTH, const bool &onf = false,
           const float &h = DEF_GAMEHERO_HEALTH, const bool &facingR = true, const float &s = HERO_SPEED);
    virtual ~Knight() {};

    //default constructor
    Knight();

    //copy constructor
    Knight(const Knight &copied);

    //assignment operator
    Knight& operator=(const Knight& initializer) = default;

    void specialBehaviour() override;

    void move(const Direction& direction, const float& distance) override;

private:
    void initSprite(const float &x, const float &y);

    void giveHitbox();
};

#endif //_KNIGHT_H