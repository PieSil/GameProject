//
// Created by Pietro on 2019-06-28.
//

#include "ShootingCharacter.h"


ShootingCharacter::ShootingCharacter(const float &x, const float &y, const float &str, const bool &onf, const float &h,
                             const float &s, const bool &facingR) : GameCharacter(x,y, str, onf, h, s, facingR) {

}

ShootingCharacter::ShootingCharacter(const ShootingCharacter &copied) : GameCharacter(copied) {

}

ShootingCharacter::ShootingCharacter() :GameCharacter(0,0) {

}

void ShootingCharacter::attack() {

}
