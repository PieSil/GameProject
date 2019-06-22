/**
 * Project Game
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"


class GameHero: public GameCharacter {
public:
    GameHero(int x, int y, bool onf = false, float h = DEFHealth);
    virtual ~GameHero() {};
    
virtual void specialBehaviour() = 0;

protected:
    static const float DEFHealth;
};

#endif //_GAMEHERO_H