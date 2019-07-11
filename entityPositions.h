//
// Created by Pietro on 2019-07-07.
//

#ifndef GAMEPROJECT_ENTITYPOSITIONS_H
#define GAMEPROJECT_ENTITYPOSITIONS_H

#include <SFML/Graphics.hpp>

struct EntityPositions {
    sf::Vector2f spritePosition;
    sf::Vector2f hitboxPosition;
    sf::Vector2f upperEdgePosition;
    sf::Vector2f lowerEdgePosition;
    sf::Vector2f leftEdgePosition;
    sf::Vector2f rightEdgePosition;
    int gridPositionX;
    int gridPositionY;
    bool facingRight;
};

#endif //GAMEPROJECT_ENTITYPOSITIONS_H
