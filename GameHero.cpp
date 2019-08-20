/**
 * Project Game
 */

#include "GameHero.h"
#include "gameValues.h"

/**
 * GameHero implementation
 */

GameHero::GameHero(const float &x, const float &y, const float &str, const bool &onf, const float &h,
                   const bool &facingR, const float &s) : GameCharacter(x, y, str, onf, h, s, facingR), abilityTimeStep(KNIGHT_ABILITY_TIMESTEP), abilityAvailable(true) {

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

/*
const bool GameHero::abilityAvailable() {
    bool canUse = false;

    if(this->clocks.abilityClock.getElapsedTime().asSeconds() >= abilityTimeStep && !this->isAttacking() && !this->isDying()) {
        canUse = true;
    }

    return canUse;
}
*/

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

const bool GameHero::getDamaged(const float &damage) {
    return GameCharacter::getDamaged(damage);
}

void GameHero::animate() {

    if (state == EntityState::ABILITY) {
        if (animManager.getCurrentFrame(EntityState::ABILITY) == getParameters()->abilityLastCol) { //if animation is on last frame
            animManager.resetAnimation(EntityState::ABILITY); //reset animation to the beginning
            state = EntityState::IDLE; //reset state to idle to avoid looping the animation
        }
    }

    GameCharacter::animate();
}

void GameHero::updateStatus() {
    GameCharacter::updateStatus();

    if(this->clocks.abilityClock.getElapsedTime().asSeconds() >= abilityTimeStep && !this->isAttacking() && !this->isDying()) {
        abilityAvailable = true;
    }

}
/*
void GameHero::updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) {
}
 */
