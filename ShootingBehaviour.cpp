//
// Created by Pietro on 2019-07-08.
//

#include "ShootingBehaviour.h"

void ShootingBehaviour::attack(State &state) {
    if (state != ATTACKING && state != SHOOTING && clock.getElapsedTime().asSeconds() > 1) {
        clock.restart();
        state = SHOOTING;
    }
}
