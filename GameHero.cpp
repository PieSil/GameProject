/**
 * Project Game
 */

#include "GameHero.h"
#include "gameValues.h"

/**
 * GameHero implementation
 */

GameHero::GameHero(const float &x, const float &y, const float &str, const bool &onf, const float &h,
                   const bool &facingR, const float &s) : GameCharacter(x, y, str, onf, h, s, facingR) {

}

GameHero::GameHero() : GameHero(0,0) {

}

GameHero::GameHero(const GameHero &copied) : GameCharacter(copied) {

}

void GameHero::move(const Direction &direction, const float &distance) {
    MovingEntity::move(direction, distance);
    notifyObservers();
}

/*
void GameHero::updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) {
}
 */
