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
    Tile(const sf::Vector2f &position, bool walkable = false) : walkable(walkable) {
        if (!walkable) {
            hitbox = Hitbox(position, TILE_SIZE.x, TILE_SIZE.y);
        } else {
            hitbox = Hitbox(position, 0, 0);
        }
    };

    void setPosition(const sf::Vector2f& position) {
        hitbox.setPosition(position);
    };

    const Hitbox &getHitbox() const {
        return hitbox;
    }

protected:
    Hitbox hitbox;
    bool walkable;
    bool destructible;
};

#endif //_TILE_H