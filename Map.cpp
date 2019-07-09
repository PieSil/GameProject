/**
 * Project Game
 */


#include "Map.h"

/**
 * Map implementation
 */
Map::Map(const int *tilesArray, const int &arrayColumns, const int &arrayRows, const std::string &path,
         sf::Vector2u tileSize) : tilesArray(tilesArray), columns(arrayColumns), rows(arrayRows), tileSize(tileSize) {
    if (!tileset.loadFromFile(path)) {
        //TODO: throw exception
    }

    load();

}

void Map::load() {

    // resize the vertex array to fit the level size
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(columns * rows * 4); //4 vertex for each quad of the VertexArray: number of vertices = map size * 4

    // file the vertex array, each tiles corresponds to a quad:

    for (unsigned int i = 0; i < rows; ++i) { //move on columns, i is the row index
        for (unsigned int j = 0; j < columns; ++j) { //move on rows, j is the column index

            // get the current tile number
            int tileNumber = tilesArray[j + i * columns]; // i + j*columns finds the ij element in the matrix


                // find its position in the tileset texture
                int tileTop = tileNumber % (tileset.getSize().x / tileSize.x);
                int tileLeft = tileNumber / (tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex *quad = &vertices[(j + i * columns) * 4]; //multiply by 4 because each quad is made of 4 vertices

                // define its 4 corners
                quad[0].position = sf::Vector2f(j * tileSize.x, i * tileSize.y); //top left corner
                quad[1].position = sf::Vector2f((j + 1) * tileSize.x, i * tileSize.y); //top right corner
                quad[2].position = sf::Vector2f((j + 1) * tileSize.x, (i + 1) * tileSize.y); //bottom right corner
                quad[3].position = sf::Vector2f(j * tileSize.x, (i + 1) * tileSize.y); //bottom left corner

                if (tileNumber != 0) {
                    tiles.emplace_back(Tile(sf::Vector2f((quad[0].position.x + quad[1].position.x) / 2.,
                                                         (quad[0].position.y + quad[3].position.y) / 2.)));
                    // define its 4 texture coordinates
                    quad[0].texCoords = sf::Vector2f(tileTop * tileSize.x, tileLeft * tileSize.y); //top left corner
                    quad[1].texCoords = sf::Vector2f((tileTop + 1) * tileSize.x, tileLeft * tileSize.y); //top right corner
                    quad[2].texCoords = sf::Vector2f((tileTop + 1) * tileSize.x,
                                                     (tileLeft + 1) * tileSize.y); //bottom right corner
                    quad[3].texCoords = sf::Vector2f(tileTop * tileSize.x,
                                                     (tileLeft + 1) * tileSize.y); //bottom left corner

                } else {
                    tiles.emplace_back(Tile(sf::Vector2f((quad[0].position.x + quad[1].position.x) / 2.,
                                                         (quad[0].position.y + quad[3].position.y) / 2.), true));
                }
        }
    }
}

const std::vector<Tile> &Map::getTiles() const {
    return tiles;
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileset;

    // draw the vertex array
    target.draw(vertices, states);
}
