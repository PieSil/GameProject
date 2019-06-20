/**
 * Project Game
 */


#ifndef _TILE_H
#define _TILE_H

#include "Map.h"


class Tile: public Map {
protected: 
    int height;
    int width;
    int posX;
    int posY;
    bool walkable;
    bool destructible;
};

#endif //_TILE_H