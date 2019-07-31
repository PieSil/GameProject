//
// Created by Pietro on 2019-06-30.
//

#ifndef GAMEPROJECT_SPRITEPARAMETERS_H
#define GAMEPROJECT_SPRITEPARAMETERS_H

#include <iostream>

struct SpriteParams {
public:
    SpriteParams(const std::string &path, const int &width, const int &height, const float scale = 1, const float &widthRed = 1,
                 const float &heightRed = 1, const unsigned short &idleRow = 0, const unsigned short idleCol = 0,
                 const unsigned short movRow = 0, const unsigned short movLastCol = 0, const int &attRow = 0, const int &attLastCol = 0,
                 const int &attOffset = 0, const int &shootRow = 0, const int &shootLastCol = 0, const int &deathRow = 0,
                 const int &deathLastCol = 0, const int &abilityRow = 0, const int &abilityLastCol = 0)
            : width(width), height(height), widthRed(widthRed), heightRed(heightRed), scale(scale), path(path),
              idleRow(idleRow), idleLastCol(idleCol), movRow(movRow), movLastCol(movLastCol), attRow(attRow),
              attLastCol(attLastCol), attOffset(attOffset), shootRow(shootRow), shootLastCol(shootLastCol), deathRow(deathRow), deathLastCol(deathLastCol),
              abilityRow(abilityRow), abilityLastCol(abilityLastCol){};

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

    const int attRow;
    const int attLastCol;

    const int attOffset;

    const int shootRow;
    const int shootLastCol;

    const int deathRow;
    const int deathLastCol;

    const int abilityRow;
    const int abilityLastCol;
};

#endif //GAMEPROJECT_SPRITEPARAMETERS_H
