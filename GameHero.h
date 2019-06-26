/**
 * Project Game
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "defaultValues.h"


class GameHero: public GameCharacter {
public:
    GameHero(const float &x, const float &y, const float &str = DEF_GAMEHERO_STRENGTH, const bool &onf = false,
             const float &h = DEF_GAMEHERO_HEALTH, const bool &facingR = true, const float &s = HERO_SPEED);
    virtual ~GameHero() {};
    //default constructor
    GameHero();

    //copy constructor
    GameHero(const GameHero& copied);
    
virtual void specialBehaviour() = 0;

    void updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) override;

    void updateMovement(int width, int height, float scale, int rowSelector, int lastColumn) override;

};

#endif //_GAMEHERO_H