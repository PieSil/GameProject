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
                             MovingEntity(x, y, s, facingR) {

}

GameCharacter::~GameCharacter() {};

void GameCharacter::attack() {

}

GameCharacter::GameCharacter() : GameCharacter(0,0) {

}

GameCharacter::GameCharacter(const GameCharacter &copied) : health(copied.getHealth()), onFire(copied.isOnFire()),
                                                            strength(copied.getStrength()), MovingEntity(copied) {

}
