/**
 * Project Game
 */


#include "GameHero.h"

/**
 * GameHero implementation
 */

const float GameHero::DEFHealth = 20.;

GameHero::GameHero(int x, int y, bool onf, float h) : GameCharacter(x, y, onf, h) {}
