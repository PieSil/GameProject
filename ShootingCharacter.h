//
// Created by Pietro on 2019-06-28.
//

#ifndef GAMEPROJECT_SHOOTINGCHARACTER_H
#define GAMEPROJECT_SHOOTINGCHARACTER_H

#include "GameCharacter.h"

class ShootingCharacter : public virtual GameCharacter {

public:
    ShootingCharacter(const float &x, const float &y, const float &str = 5., const bool &onf = false, const float &h = 10,
                      const float &s = 1., const bool &facingR = true);

    ShootingCharacter();

    //copy constructor
    ShootingCharacter(const ShootingCharacter& copied);

    virtual ~ShootingCharacter() {};

    //overides attack method to shoot projectiles
    const float & attack() override;

};


#endif //GAMEPROJECT_SHOOTINGCHARACTER_H
