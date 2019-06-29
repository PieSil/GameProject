//
// Created by Pietro on 2019-06-22.
//

#ifndef GAMEPROJECT_GAMEVALUES_H
#define GAMEPROJECT_GAMEVALUES_H

#include <iostream>

//Alias definitions

//use Direction as alias of unsigned short int to simplify readability
using Direction = unsigned short int;

const Direction RIGHT = 0;

const Direction LEFT = 1;

const Direction UP = 2;

const Direction  DOWN = 3;

//use Herotype as alias of unsigned short int to simplify readability
using Heroytype = char;

const Heroytype KNGT = 'k'; //Knight hero type, not called KNIGHT to avoid confusion with Knight class

const Heroytype WZRD = 'w';//Wizard hero type, not called WIZARD to avoid confusion with Wizard class


//GAME

//used to set game framerate and updating speed (avoid setting framerate to an excessive value)
const float FRAMERATE = 60.;


//animation counter increment, helps controlling the speed of character animations -> higher value = lower speed
//a good value is 30/FRAMERATE
const float ANIM_COUNT_INCR = 0.5;

//GRAVITY modyfing this values may break game physics

//controls gravity intensity, with current physics system value should be -2 or higher (meaning between -2 and 0)
const float GRAVITY = -2;


//controls starting jump velocity
const float JUMP_VELOCITY = 30;

//HITBOXES

//set thickness of hitboxes' edges, the bigger the value the easier is to detect collisions
//excessive value may cause problems with collision
const int EDGE_THICKNESS = 5;

//HERO

//default health value for all game heroes:
const float DEF_GAMEHERO_HEALTH = 20.;

//default strength value for all game heroes:
const float DEF_GAMEHERO_STRENGTH = 5.;

//default value for hero movementSpeed parameter:
const float HERO_SPEED = 300; //sets hero speed (measured in pixels/second ?)

//KNIGHT

//values used to determine knight's sprite width and heigth to correctly select it when cutting sprite sheet:
const int KNIGHT_WIDTH = 42;
const int KNIGHT_HEIGHT = 42;

//values that allow to reduce hitbox size when giving it to the sprite
//THESE DO NOT DIRECTLY SET HITBOX SIZE, they allow to resize it based on sprite size
const float KNIGHT_HITBOX_X = 4;
const float KNIGHT_HITBOX_Y = 1.2;

//value used to scale up/down or flip knight's sprite:
const float KNIGHT_SCALE = 4.;

//value used to set path of texture file
const std::string KNIGHT_PATH = "../GameAssets/Sprites/Player/Knight/Knight.png";

//values used to choose starting sprite
const int KNIGHT_IDLE_ROW = 0;
const int KNIGHT_IDLE_COL = 0;


//values used to choose row and last column of walking animation in the spritesheet:
const int KNIGHT_MOV_ROW =4;
const int KNIGHT_MOV_LAST_COL = 7;

//WIZARD

//values used to determine wizard's sprite width and heigth to correctly select it when cutting sprite sheet:
const int WIZARD_WIDTH = 48;
const int WIZARD_HEIGHT = 48;

//values that allow to reduce hitbox size when giving it to the sprite
//THESE DO NOT DIRECTLY SET HITBOX SIZE, they allow to resize it based on sprite size
const float WIZARD_HITBOX_X = 1.8;
const float WIZARD_HITBOX_Y = 1;

//value used to set path of texture file
const std::string WIZARD_PATH = "../GameAssets/Sprites/Player/Wizard/Wizard.png";

//values used to choose starting sprite
const int WIZARD_IDLE_ROW = 0;
const int WIZARD_IDLE_COL = 0;

//value used to scale up/down or flip wizard's sprite:
const float WIZARD_SCALE = 2.;

//values used to choose row and last column of walking animation in the spritesheet:
const int WIZARD_MOV_ROW_SELECTOR =2;
const int WIZARD_MOV_LAST_COL = 3;

//ENEMY

//default health value for all enemies:
const float DEF_ENEMY_HEALTH = 35.;

//default strength value for all enemies:
const float DEF_ENEMY_STRENGTH = 3.;

//default value for enemy movementSpeed parameter:
const float ENEMY_SPEED = 400; //sets hero speed (measured in pixels/second ?)

//MELEE

//values used to determine sprite's width and heigth to correctly select it when cutting sprite sheet:
const int MELEE_WIDTH = 48;
const int MELEE_HEIGHT = 48;

//values that allow to reduce hitbox size when giving it to the sprite
//THESE DO NOT DIRECTLY SET HITBOX SIZE, they allow to resize it based on sprite size
const float MELEE_HITBOX_X = 2.8;
const float MELEE_HITBOX_Y = 1.2;

//value used to scale up/down or flip sprite:
const float MELEE_SCALE = 3.5;

//value used to set path of texture file
const std::string MELEE_PATH = "../GameAssets/Sprites/Enemies/Bandit/Bandit.png";

//values used to choose starting sprite
const int MELEE_IDLE_ROW = 0;
const int MELEE_IDLE_COL = 0;


//values used to choose row and last column of walking animation in the spritesheet:
const int MELEE_MOV_ROW =1;
const int MELEE_MOV_LAST_COL = 7;

#endif //GAMEPROJECT_GAMEVALUES_H
