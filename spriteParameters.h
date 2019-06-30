//
// Created by Pietro on 2019-06-30.
//

#ifndef GAMEPROJECT_SPRITEPARAMETERS_H
#define GAMEPROJECT_SPRITEPARAMETERS_H

#include <iostream>

struct SpriteParams {
public:
    SpriteParams(const int &width, const int &height, const float &widthRed, const float &heightRed, const float scale,
                 const std::string &path,
                 const unsigned short &idleRow, const unsigned short idleCol, const unsigned short movRow,
                 const unsigned short movLastCol) : width(width), height(height), widthRed(widthRed),
                                                    heightRed(heightRed), scale(scale),
                                                    path(path), idleRow(idleRow), idleLastCol(idleCol), movRow(movRow),
                                                    movLastCol(movLastCol) {};

    //values used to determine sprite width and heigth to correctly select it when cutting sprite sheet:
    const int width;
    const int height;

//values that allow to reduce hitbox size when giving it to the sprite
    const float widthRed;
    const float heightRed;

//value used to scale up/down or flip sprite:
    const float scale;

//value used to set path of texture file
    const std::string path = "../GameAssets/Sprites/Player/Knight/Knight.png";

//values used to choose starting sprite
    const unsigned short idleRow;
    const unsigned short idleLastCol;


//values used to choose row and last column of walking animation in the spritesheet:
    const unsigned short movRow;
    const unsigned short movLastCol;
};

#endif //GAMEPROJECT_SPRITEPARAMETERS_H
