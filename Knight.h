/**
 * Project Game
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "GameHero.h"


class Knight: public GameHero {
public:
    Knight(float x, float y, float str = DEF_GAMEHERO_STRENGTH, bool onf = false, float h = DEF_GAMEHERO_HEALTH, bool facingR = true, float s = HERO_SPEED);
    virtual ~Knight() {};

    //default constructor
    Knight();

    //copy constructor
    Knight(Knight &copied);

    //assignment operator
    Knight& operator=(const Knight& initializer) = default;

    void specialBehaviour() override;

    void move(const Direction& direction, const float& distance);

    void initSprite(float x, float y) override;
};

#endif //_KNIGHT_H