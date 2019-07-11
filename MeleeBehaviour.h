//
// Created by Pietro on 2019-07-08.
//

#ifndef GAMEPROJECT_MELEEBEHAVIOUR_H
#define GAMEPROJECT_MELEEBEHAVIOUR_H

#include "AttackBehaviour.h"
#include "math.h"

class MeleeBehaviour : public AttackBehaviour {
public:

    MeleeBehaviour() = default;

    ~MeleeBehaviour() {};

    const std::pair<bool, Hitbox> attack(State &state, const EntityPositions &allPositions, const float &attackRange) override;

};


#endif //GAMEPROJECT_MELEEBEHAVIOUR_H
