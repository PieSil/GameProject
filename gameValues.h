//
// Created by Pietro on 2019-06-22.
//

#ifndef GAMEPROJECT_GAMEVALUES_H
#define GAMEPROJECT_GAMEVALUES_H

#include <iostream>
#include <SFML/Graphics.hpp>

//Alias definitions

//use Direction as alias of unsigned short int to simplify readability
using Direction = unsigned short int;

const Direction RIGHT = 0;

const Direction LEFT = 1;

const Direction UP = 2;

const Direction  DOWN = 3;

//use Herotype as alias of unsigned short int to simplify readability
using Herotype = char;

const Herotype KNGT = 'k'; //Knight hero type, not called KNIGHT to avoid confusion with Knight class

const Herotype WZRD = 'w';//Wizard hero type, not called WIZARD to avoid confusion with Wizard class

using State = unsigned short;

const State IDLE = 0;

const State WALKING = 1;

const State ATTACKING = 2;

const State SHOOTING = 3;

//GAME

//used to set game framerate and updating speed (avoid setting framerate to an excessive value)
const float FRAMERATE = 60.;


//sets walking animation duration
const float WALK_ANIM_TIME = 0.5;

//sets idle animation duration
const float IDLE_ANIM_TIME = 1;

const float ATT_ANIM_TIME = 0.5;
const float SHOOT_ANIM_TIME = 0.5;

//GRAVITY modifying this values may break game physics

//controls gravity intensity, with current physics system value should be -2 or higher (meaning between -2 and 0)
const float GRAVITY = -0.5;


//controls starting jump velocity
const float JUMP_VELOCITY = 8;

//MAP

const std::string MAP_PATH = "../GameAssets/Tileset/Tileset.png";
const sf::Vector2u TILE_SIZE(32,32);
const int MAP_COLUMNS = 71;
const int MAP_ROWS = 10;

//HITBOXES

//set thickness of hitboxes' edges, the bigger the value the easier is to detect collisions
//excessive value may cause problems with collision
const int EDGE_THICKNESS = 1;

//HERO

//default health value for all game heroes:
const float DEF_HERO_HEALTH = 20.;

//default strength value for all game heroes:
const float DEF_HERO_STRENGTH = 5.;

//default attack range for all game heroes:
const float HERO_ATTACK_RANGE = 16;


//default value for hero movementSpeed parameter:
const float HERO_SPEED = 60; //sets hero speed (measured in pixels/second ?)

//KNIGHT

//values used to determine knight's sprite width and heigth to correctly select it when cutting sprite sheet:

const float KNIGHT_ATTACK_RANGE = 16;

const int KNIGHT_WIDTH = 42;
const int KNIGHT_HEIGHT = 42;

//values that allow to reduce hitbox size when giving it to the sprite
//THESE DO NOT DIRECTLY SET HITBOX SIZE, they allow to resize it based on sprite size
const float KNIGHT_HITBOX_X = 4;
const float KNIGHT_HITBOX_Y = 1.2;

//value used to scale up/down or flip knight's sprite:
const float KNIGHT_SCALE = 0.7619047619;

//value used to set path of texture file
const std::string KNIGHT_PATH = "../GameAssets/Sprites/Player/Knight/Knight.png";

//values used to choose starting sprite
const int KNIGHT_IDLE_ROW = 1;
const int KNIGHT_IDLE_LAST_COL = 3;


//values used to choose row and last column of walking animation in the spritesheet:
const int KNIGHT_MOV_ROW =4;
const int KNIGHT_MOV_LAST_COL = 7;

const int KNIGHT_ATT_ROW =2;
const int KNIGHT_ATT_LAST_COL = 8;

const int KNIGHT_ATT_OFFSET = 38;

const int KNIGHT_SHOOT_ROW =2;
const int KNIGHT_SHOOT_LAST_COL = 8;

//WIZARD

const float WIZARD_ATTACK_RANGE = 0;

//values used to determine wizard's sprite width and heigth to correctly select it when cutting sprite sheet:
const int WIZARD_WIDTH = 32;
const int WIZARD_HEIGHT = 32;

//values that allow to reduce hitbox size when giving it to the sprite
//THESE DO NOT DIRECTLY SET HITBOX SIZE, they allow to resize it based on sprite size
const float WIZARD_HITBOX_X = 2.4;
const float WIZARD_HITBOX_Y = 1;

//value used to set path of texture file
const std::string WIZARD_PATH = "../GameAssets/Sprites/Player/Wizard/Wizard.png";

//values used to choose starting sprite
const int WIZARD_IDLE_ROW = 0;
const int WIZARD_IDLE_LAST_COL = 9;

//value used to scale up/down or flip wizard's sprite:
const float WIZARD_SCALE = 0.8;

//values used to choose row and last column of walking animation in the spritesheet:
const int WIZARD_MOV_ROW =2;
const int WIZARD_MOV_LAST_COL = 9;

const int WIZARD_ATT_ROW =3;
const int WIZARD_ATT_LAST_COL = 9;

const int WIZARD_ATT_OFFSET = 0;

const int WIZARD_SHOOT_ROW =3;
const int WIZARD_SHOOT_LAST_COL = 9;

//ENEMY

//default health value for all enemies:
const float DEF_ENEMY_HEALTH = 35.;

//default strength value for all enemies:
const float DEF_ENEMY_STRENGTH = 3.;

//default value for enemy movementSpeed parameter:
const float ENEMY_SPEED = 30; //sets hero speed (measured in pixels/second ?)

//MELEE

const float MELEE_ATTACK_RANGE = 16;

//values used to determine sprite's width and heigth to correctly select it when cutting sprite sheet:
const int MELEE_WIDTH = 48;
const int MELEE_HEIGHT = 48;

//values that allow to reduce hitbox size when giving it to the sprite
//THESE DO NOT DIRECTLY SET HITBOX SIZE, they allow to resize it based on sprite size
const float MELEE_HITBOX_X = 2.8;
const float MELEE_HITBOX_Y = 1.2;

//value used to scale up/down or flip sprite:
const float MELEE_SCALE = 0.6666666667;

//value used to set path of texture file
const std::string MELEE_PATH = "../GameAssets/Sprites/Enemies/Bandit/Bandit.png";

//values used to choose starting sprite
const int MELEE_IDLE_ROW = 0;
const int MELEE_IDLE_LAST_COL = 7;


//values used to choose row and last column of walking animation in the spritesheet:
const int MELEE_MOV_ROW =1;
const int MELEE_MOV_LAST_COL = 7;

const int MELEE_ATT_ROW =2;
const int MELEE_ATT_LAST_COL = 7;

const int MELEE_ATT_OFFSET = 0;

const int MELEE_SHOOT_ROW =2;
const int MELEE_SHOOT_LAST_COL = 7;

//BOSS

const float BOSS_ATTACK_RANGE =32;
const float BOSS_SHOOT_RANGE = 64;

const float BOSS_SPEED = 15;

const int BOSS_WIDTH = 96;
const int BOSS_HEIGHT = 96;

//values that allow to reduce hitbox size when giving it to the sprite
//THESE DO NOT DIRECTLY SET HITBOX SIZE, they allow to resize it based on sprite size
const float BOSS_HITBOX_X = 3.4;
const float BOSS_HITBOX_Y = 3;

//value used to scale up/down or flip sprite:
const float BOSS_SCALE = 1;

//value used to set path of texture file
const std::string BOSS_PATH = "../GameAssets/Sprites/Enemies/Boss/Boss.png";

//values used to choose starting sprite
const int BOSS_IDLE_ROW = 0;
const int BOSS_IDLE_LAST_COL = 4;


//values used to choose row and last column of walking animation in the spritesheet:
const int BOSS_MOV_ROW =1;
const int BOSS_MOV_LAST_COL = 7;

const int BOSS_ATT_ROW =3;
const int BOSS_ATT_LAST_COL = 8;

const int BOSS_ATT_OFFSET = 0;

const int BOSS_SHOOT_ROW =4;
const int BOSS_SHOOT_LAST_COL = 4;

//PROJECTILE

const float PROJ_SPEED = 100;

//FIREBALL

const int FIREB_WIDTH = 100;
const int FIREB_HEIGHT = 100;

//values that allow to reduce hitbox size when giving it to the sprite
//THESE DO NOT DIRECTLY SET HITBOX SIZE, they allow to resize it based on sprite size
const float FIREB_HITBOX_X = 3;
const float FIREB_HITBOX_Y = 3;

//value used to scale up/down or flip sprite:
const float FIREB_SCALE = 0.15;

//value used to set path of texture file
const std::string FIREB_PATH = "../GameAssets/Sprites/Projectiles/Fireball/Fireball.png";

//values used to choose starting sprite
const int FIREB_IDLE_ROW = 0;
const int FIREB_IDLE_LAST_COL = 7;


//values used to choose row and last column of walking animation in the spritesheet:
const int FIREB_MOV_ROW =0;
const int FIREB_MOV_LAST_COL = 7;

const int FIREB_ATT_ROW =0;
const int FIREB_ATT_LAST_COL = 7;

const int FIREB_SHOOT_ROW =0;
const int FIREB_SHOOT_LAST_COL = 7;


#endif //GAMEPROJECT_GAMEVALUES_H
