//
// Created by Pietro on 2019-07-08.
//

#include "AttackBehaviour.h"

const bool AttackBehaviour::canAttack(const EntityState &state) {

    bool canAttack = false;

    if (state != EntityState::MELEE && state != EntityState::SHOOTING && state != EntityState::ABILITY)
        canAttack = true;

    return canAttack;
}
