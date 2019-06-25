/**
 * Project Game
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "GameHero.h"


class Knight: public GameHero {
public:
    Knight(float x, float y, bool onf = false, float h = defHealth, bool facingR = true, float s = HERO_SPEED);
    virtual ~Knight() {};

    void specialBehaviour() override;

    void updateInput();
};

#endif //_KNIGHT_H