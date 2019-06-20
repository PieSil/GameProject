/**
 * Project Game
 */


#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameCharacter.h"


class Enemy: public GameCharacter {
protected: 
    bool paralyzed;
};

#endif //_ENEMY_H