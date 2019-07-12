//
// Created by Pietro on 2019-07-08.
//

#ifndef GAMEPROJECT_SHOOTINGBEHAVIOUR_H
#define GAMEPROJECT_SHOOTINGBEHAVIOUR_H

#include "AttackBehaviour.h"

class ShootingBehaviour : public AttackBehaviour {
public:

    ShootingBehaviour() = default;

    ~ShootingBehaviour() {};
    const std::pair<bool, Hitbox> attack(EntityState &state, const EntityPositions &allPositions, const float &attackRange) override;

};


#endif //GAMEPROJECT_SHOOTINGBEHAVIOUR_H
