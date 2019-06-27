/**
 * Project Game
 */

#include "GameHero.h"
#include "defaultValues.h"

/**
 * GameHero implementation
 */

GameHero::GameHero(float x, float y, float str, bool onf, float h, bool facingR, float s) : GameCharacter(x, y, str, onf, h, s, facingR) {

}

GameHero::GameHero() : GameHero(0,0) {

}

GameHero::GameHero(GameHero &copied) : GameCharacter(copied) {

}

/*
void GameHero::updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) {
}
 */
