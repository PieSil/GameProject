/**
 * Project Game
 */


#include "GameCharacter.h"
#include "GameEntity.h"
#include "math.h"

/**
 * GameCharacter implementation
 */

GameCharacter::GameCharacter(float x, float y, float str, bool onf, float h, float s, bool facingR) :
                             onFire(onf), health(abs(h)), strength(abs(str)),
                             GameEntity(x, y, s, facingR, sf::Texture(), sf::RectangleShape(), sf::Text()) {

}

GameCharacter::~GameCharacter() {};

void GameCharacter::attack() {

}

void GameCharacter::jump() {

}

GameCharacter::GameCharacter() : GameCharacter(0,0) {

}

GameCharacter::GameCharacter(GameCharacter &copied) : health(copied.getHealth()), onFire(copied.isOnFire()),
                                                      strength(copied.getStrength()), GameEntity(copied) {

}
