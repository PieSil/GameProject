/**
 * Project Game
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "GameHero.h"


class Knight: public GameHero {
    Knight(int x,int y, float h = DEFHealth, bool onf = false);
    virtual ~Knight() {};
};

#endif //_KNIGHT_H