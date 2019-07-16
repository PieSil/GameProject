/**
 * Project Game
 */


#include "Tile.h"

/**
 * Tile implementation
 */

Tile::Tile(const sf::Vector2f &position, const unsigned short int& tileID) {
    switch (tileID) {

        case 0:
            //tileID corresponds to empty tile, set walkable to true
            giveHitbox(position);
            walkable = true;
            deadly = false;
            break;

        case 8:
            //tileID corresponds to spikes, give the tile a hitbox that is half in height and set deadly to true
            giveHitbox(sf::Vector2f(position.x, position.y + TILE_SIZE.y/4.), TILE_SIZE.x, TILE_SIZE.y/2);
            walkable = false;
            deadly = true;
            break;

        default:
            giveHitbox(position);
            walkable = false;
            deadly = false;
            break;
    }
}

void Tile::giveHitbox(const sf::Vector2f &position, const int &width, const int &height) {
    hitbox = Hitbox(position, width, height);
}
