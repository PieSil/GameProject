/**
 * Project Game
 */


#ifndef _TILE_H
#define _TILE_H

#include <SFML/Graphics.hpp>
#include "Hitbox.h"
#include "gameValues.h"

class Tile {
public:

    Tile(const sf::Vector2f &position, const unsigned short int& tileID);

    void giveHitbox(const sf::Vector2f &position, const int &width = TILE_SIZE.x, const int &height = TILE_SIZE.y);

    void setPosition(const sf::Vector2f& position) {
        hitbox.setPosition(position);
    };

    const Hitbox &getHitbox() const {
        return hitbox;
    }

    bool isWalkable() const {
        return walkable;
    }

    bool isDeadly() const {
        return deadly;
    }

protected:
    Hitbox hitbox;
    bool walkable;
    bool deadly;
};

#endif //_TILE_H