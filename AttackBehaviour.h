//
// Created by Pietro on 2019-07-08.
//

#ifndef GAMEPROJECT_ATTACKBEHAVIOUR_H
#define GAMEPROJECT_ATTACKBEHAVIOUR_H

#include "gameValues.h"
#include "entityPositions.h"
#include "Hitbox.h"

class AttackBehaviour {
public:
    virtual ~AttackBehaviour() {};

    virtual const std::pair<bool, Hitbox>
    attack(EntityState &state, const EntityPositions &allPositions, const float &attackRange) = 0;

};


#endif //GAMEPROJECT_ATTACKBEHAVIOUR_H
