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

void GameCharacter::attack() {

}

void GameCharacter::jump() {

}