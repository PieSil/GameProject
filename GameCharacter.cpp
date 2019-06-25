/**
 * Project Game
 */


#include "GameCharacter.h"
#include "GameEntity.h"

/**
 * GameCharacter implementation
 */

GameCharacter::GameCharacter(float x, float y, bool onf, float h, float s, bool facingR) :  onFire(onf), health(h),
                             GameEntity(x, y, s, facingR, sf::Texture(), sf::RectangleShape(), sf::Text()) {

}

GameCharacter::~GameCharacter() {};

void GameCharacter::attack() {

}

void GameCharacter::jump() {

}

GameCharacter::GameCharacter() : GameCharacter(0,0) {

}

GameCharacter::GameCharacter(const GameCharacter &copied) : health(copied.getHealth()), onFire(copied.isOnFire()),
                             GameEntity(copied) {

}
