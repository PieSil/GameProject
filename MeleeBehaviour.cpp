//
// Created by Pietro on 2019-07-08.
//

#include "MeleeBehaviour.h"


const std::pair<bool, Hitbox> MeleeBehaviour::attack(State &state, const EntityPositions &allPositions,
                                                     const float &attackRange) {

    /*
     * if (character->isFacingRight()) //if character is facing right create hitbox to its right

        //x position of the hitbox is set so that attackHitbox's left edge overlaps with chracter's hitbox right edge
        attackHitbox = Hitbox(
                sf::Vector2f(character->getAllPositions().rightEdgePosition.x + character->getAttackRange() / 2.,
                             character->getAllPositions().spritePosition.y), character->getAttackRange(),
                abs(character->getAllPositions().upperEdgePosition.y -
                    character->getAllPositions().lowerEdgePosition.y));

    else //else create hitbox to its left

        //x position of the hitbox is set so that attackHitbox's right edge overlaps with chracter's hitbox left edge
        attackHitbox = Hitbox(
                sf::Vector2f(character->getAllPositions().leftEdgePosition.x - character->getAttackRange() / 2.,
                             character->getAllPositions().spritePosition.y), character->getAttackRange(),
                (abs(character->getAllPositions().upperEdgePosition.y - character->getAllPositions().lowerEdgePosition.y)));
     */

    std::pair<bool, Hitbox> result;

    if (state != ATTACKING && state != SHOOTING) {
        state = ATTACKING;
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
