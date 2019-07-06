/**
 * Project Game
 */


#ifndef _TILE_H
#define _TILE_H

#include <SFML/Graphics.hpp>
#include "gameValues.h"

class Tile {
public:
    Tile(const sf::Vector2f &position) {
        hitbox.setSize(sf::Vector2f(TILE_SIZE));
        hitbox.setOrigin(hitbox.getSize().x/2., hitbox.getSize().y/2.);
        hitbox.setFillColor(sf::Color::White);
        setPosition(position);
    };

    void setPosition(const sf::Vector2f& position) {
        hitbox.setPosition(position);
    };

    const sf::RectangleShape &getHitbox() const {
        return hitbox;
    }

protected:
    sf::RectangleShape hitbox;
    bool walkable;
    bool destructible;
};

#endif //_TILE_H