//
// Created by Pietro on 2019-07-08.
//

#include "ShootingBehaviour.h"

const std::pair<bool, Hitbox> ShootingBehaviour::attack(EntityState &state, const EntityPositions &allPositions,
                                                        const float &attackRange) {

    std::pair<bool, Hitbox> result;

    if (state != EntityState::MELEE && state != EntityState::SHOOTING && state != EntityState::ABILITY) {
        state = EntityState::SHOOTING;
        result.first = true;
        result.second = Hitbox(allPositions.spritePosition, 0, 0);

    } else {
        result.first = false;

    }

    return result;
}
