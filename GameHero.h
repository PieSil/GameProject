/**
 * Project Game
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "defaultValues.h"


class GameHero: public GameCharacter {
public:
    GameHero(float x, float y, float str = DEF_GAMEHERO_STRENGTH, bool onf = false, float h = DEF_GAMEHERO_HEALTH, bool facingR = true, float s = HERO_SPEED);
    virtual ~GameHero() {};
    //default constructor
    GameHero();

    //copy constructor
    GameHero(GameHero &copied);
    
virtual void specialBehaviour() = 0;

    void updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) override;

    void updateMovement(int width, int height, float scale, int rowSelector, int lastColumn) override;

};

#endif //_GAMEHERO_H