/**
 * Project Game
 */


#include "GameHero.h"
#include "defaultValues.h"

/**
 * GameHero implementation
 */

const float GameHero::DEFHealth = DEF_GAMEHERO_HEALTH;

GameHero::GameHero(int x, int y, bool onf, float h) : GameCharacter(x, y, onf, h) {}
