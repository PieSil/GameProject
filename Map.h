/**
 * Project Game
 */


#ifndef _MAP_H
#define _MAP_H

#include <SFML/Graphics.hpp>
#include "gameValues.h"
#include "Tile.h"

class Map : public sf::Drawable, public sf::Transformable {
public:
    Map(const int* tilesArray, const int& arrayColumns, const int& arrayRows, const std::string& path = MAP_PATH, sf::Vector2u tileSize = TILE_SIZE);

    Map() = default;

    void load();

    const std::vector<Tile> &getTiles() const {
        return tiles;
    }


    void setTiles(const std::vector<Tile> &tiles) {
        Map::tiles = tiles;
    }

    const sf::VertexArray &getVertices() const {
        return vertices;
    }

    

private:

    //overrides sf::Drawable draw() method to make Map a drawable entity
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    std::vector<Tile> tiles;
    sf::VertexArray vertices;
    sf::Texture tileset;
    sf::Vector2u tileSize;
    const int* tilesArray;
    int columns;
    int rows;
};

#endif //_MAP_H