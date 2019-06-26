/**
 * Project Game
 */


#include "GameCharacter.h"
#include "GameEntity.h"
#include "math.h"

/**
 * GameCharacter implementation
 */

GameCharacter::GameCharacter(const float &x, const float &y, const float &str, const bool &onf, const float &h,
                             const float &s, const bool &facingR) :
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

GameCharacter::GameCharacter(const GameCharacter &copied) : health(copied.getHealth()), onFire(copied.isOnFire()),
                             strength(copied.getStrength()), GameEntity(copied) {

}
