//
// Created by Pietro on 2019-07-08.
//

#ifndef GAMEPROJECT_ATTACKBEHAVIOUR_H
#define GAMEPROJECT_ATTACKBEHAVIOUR_H

#include "gameValues.h"
#include "positionsStruct.h"
#include "Projectile.h"
#include "Hitbox.h"

class AttackBehaviour {
public:
    virtual ~AttackBehaviour() {};

    virtual void attack(State &state) = 0;

protected:
    sf::Clock clock;
};


#endif //GAMEPROJECT_ATTACKBEHAVIOUR_H
