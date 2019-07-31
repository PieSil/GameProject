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

GameHero::~GameHero() {}

const EntityPositions GameHero::move(const Direction &direction, const float &distance) {
    EntityPositions prevPosition;
    prevPosition = GameCharacter::move(direction, distance);

    return  prevPosition;
}

void GameHero::registerObserver(Observer *obs) {
    observers.push_back(obs);
}

void GameHero::removeObserver(Observer *obs) {
    observers.remove(obs);
}

void GameHero::notifyObservers() const {
    for (auto& observer : observers) {
        observer->update(counters.distanceWalked, counters.enemiesKilled, counters.bossKilled);
    }
}

void GameHero::incrDistanceWalked(const float &distance) {
    counters.distanceWalked += distance;
    notifyObservers();
}

void GameHero::incrEnemiesKilled(const int &enemies) {
    counters.enemiesKilled += enemies;
    notifyObservers();
}

void GameHero::setBossKilled(const bool &isKilled) {
    counters.bossKilled = isKilled;
    notifyObservers();
}

void GameHero::setupAnimations(const SpriteParams *parameters) {
    GameCharacter::setupAnimations(parameters);
    animManager.createAnimation(EntityState::ABILITY);
}

void GameHero::specialBehaviour() {
    if(state != EntityState::MELEE && state != EntityState::SHOOTING && state != EntityState::ABILITY && state != EntityState::DYING && state != EntityState::DEAD) {
        state = EntityState::ABILITY;
    }
}

/*
void GameHero::updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) {
}
 */
