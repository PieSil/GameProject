//
// Created by Pietro on 2019-07-08.
//

#include "MeleeBehaviour.h"


const std::pair<bool, Hitbox> MeleeBehaviour::attack(EntityState &state, const EntityPositions &allPositions,
                                                     const float &attackRange) {

    std::pair<bool, Hitbox> result;

    if (this->canAttack(state)) {
        state = EntityState::MELEE;
        result.first = true;

        if (allPositions.facingRight) //if character is facing right create hitbox to its right

            //x position of the hitbox is set so that attackHitbox's left edge overlaps with chracter's hitbox right edge
            result.second = Hitbox(sf::Vector2f(allPositions.rightEdgePosition.x + attackRange / 2., allPositions.spritePosition.y), attackRange, abs(allPositions.upperEdgePosition.y - allPositions.lowerEdgePosition.y));

        else //else create hitbox to its left

            //x position of the hitbox is set so that attackHitbox's right edge overlaps with chracter's hitbox left edge
            result.second = Hitbox(
                    sf::Vector2f(allPositions.leftEdgePosition.x - attackRange / 2., allPositions.spritePosition.y), attackRange,
                    (abs(allPositions.upperEdgePosition.y - allPositions.lowerEdgePosition.y)));

    } else {
        result.first = false;

    }

    return result;
}
