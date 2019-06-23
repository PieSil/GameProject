/**
 * Project Game
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "defaultValues.h"


class GameHero: public GameCharacter {
public:
    GameHero(int x, int y, bool onf = false, float h = defHealth, bool facingR = true);
    virtual ~GameHero() {};
    
virtual void specialBehaviour() = 0;

protected:
    static const float defHealth;
};

#endif //_GAMEHERO_H