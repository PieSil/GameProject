/**
 * Project Game
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "defaultValues.h"


class GameHero: public GameCharacter {
public:
    GameHero(float x, float y, bool onf = false, float h = defHealth, bool facingR = true, float s = HERO_SPEED);
    virtual ~GameHero() {};
    
virtual void specialBehaviour() = 0;

void updateMovement(int width, int height, float scale) override ;

protected:
    static const float defHealth;
};

#endif //_GAMEHERO_H