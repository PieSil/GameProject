/**
 * Project Game
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"


class GameHero: public GameCharacter {
public:
    GameHero(int x, int y, float h = DEFHealth, bool onf = false);
    virtual ~GameHero() = 0;
    
virtual void specialBehaviour();

protected:
    static const float DEFHealth;  //Default health value for all game heroes
};

#endif //_GAMEHERO_H