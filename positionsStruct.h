//
// Created by Pietro on 2019-07-07.
//

#ifndef GAMEPROJECT_POSITIONSSTRUCT_H
#define GAMEPROJECT_POSITIONSSTRUCT_H

#include <SFML/Graphics.hpp>

struct entityPositions {
    sf::Vector2f spritePosition;
    sf::Vector2f hitboxPosition;
    sf::Vector2f upperEdgePosition;
    sf::Vector2f lowerEdgePosition;
    sf::Vector2f leftEdgePosition;
    sf::Vector2f rightEdgePosition;
    int gridPositionX;
    int gridPositionY;
};

#endif //GAMEPROJECT_POSITIONSSTRUCT_H
