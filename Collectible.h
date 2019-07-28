/**
 * Project Game
 */


#ifndef _COLLECTIBLE_H
#define _COLLECTIBLE_H

#include "GameEntity.h"
#include "GameCharacter.h"


class Collectible : public GameEntity {
public:
    Collectible(const float &x, const float &y);

    virtual ~Collectible() {};

virtual void characterCollision(GameCharacter *character) = 0;

protected:
};

#endif //_COLLECTIBLE_H