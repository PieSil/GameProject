/**
 * Project Game
 */


#include "GameHero.h"

/**
 * GameHero implementation
 */

const float GameHero::DEFHealth = 20.;

GameHero::GameHero(int x, int y, float h, bool onf) : GameCharacter(x, y, h, onf) {}

void GameHero::specialBehaviour() {

}