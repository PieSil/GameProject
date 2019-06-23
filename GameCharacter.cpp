/**
 * Project Game
 */


#include "GameCharacter.h"
#include "GameEntity.h"

/**
 * GameCharacter implementation
 */

GameCharacter::GameCharacter(int x, int y, bool onf, float h, bool facingR) : posX(x), posY(y), onFire(onf), health(h),
                             GameEntity(facingR, sf::Texture(), sf::RectangleShape(),sf::Text()) {

}


void GameCharacter::attack() {

}

void GameCharacter::updateMovement() {

}

void GameCharacter::jump() {

}