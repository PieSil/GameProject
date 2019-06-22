/**
 * Project Game
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "GameHero.h"


class Knight: public GameHero {
public:
    Knight(int x,int y, bool onf = false, float h = DEFHealth);
    virtual ~Knight() {};

    void specialBehaviour() override;
};

#endif //_KNIGHT_H