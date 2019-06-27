//
// Created by Pietro on 2019-06-22.
//

#ifndef GAMEPROJECT_DEFAULTVALUES_H
#define GAMEPROJECT_DEFAULTVALUES_H

//GAME

//used to set game framerate and updating speed (avoid setting framerate to an excessive value)
const float FRAMERATE = 30.;

using Direction = unsigned short int;

const Direction RIGHT = 0;

const Direction LEFT = 1;

const Direction UP = 2;

const Direction  DOWN = 3;

//HERO

//default health value for all game heroes:
const float DEF_GAMEHERO_HEALTH = 20.;

//default strength value for all game heroes:
const float DEF_GAMEHERO_STRENGTH = 5.;

//default value for hero movementSpeed parameter:
const float HERO_SPEED = 100; //sets hero speed (measured in pixels/second ?)

//KNIGHT

//values used to determine knight's sprite width and heigth to correctly select it when cutting sprite sheet:
const int KNIGHT_WIDTH = 42;
const int KNIGHT_HEIGHT = 42;

//value used to scale up/down or flip knight's sprite:
const float KNIGHT_SCALE = 4.;

//values used to choose row and last column of walking animation in the spritesheet:
const int KNIGHT_MOV_ROW_SELECTOR =4;
const int KNIGHT_MOV_LAST_COL = 7;

//WIZARD

//values used to determine wizard's sprite width and heigth to correctly select it when cutting sprite sheet:
const int WIZARD_WIDTH = 48;
const int WIZARD_HEIGHT = 48;

//value used to scale up/down or flip wizard's sprite:
const float WIZARD_SCALE = 2.;

//values used to choose row and last column of walking animation in the spritesheet:
const int WIZARD_MOV_ROW_SELECTOR =2;
const int WIZARD_MOV_LAST_COL = 3;

#endif //GAMEPROJECT_DEFAULTVALUES_H
