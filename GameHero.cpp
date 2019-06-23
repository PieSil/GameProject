/**
 * Project Game
 */


#include "GameHero.h"
#include "defaultValues.h"

/**
 * GameHero implementation
 */

const float GameHero::defHealth = DEF_GAMEHERO_HEALTH;

GameHero::GameHero(int x, int y, bool onf, float h, bool facingR) : GameCharacter(x, y, onf, h, facingR) {

}
