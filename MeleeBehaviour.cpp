//
// Created by Pietro on 2019-07-08.
//

#include "MeleeBehaviour.h"

void MeleeBehaviour::attack(State &state) {

    if (state != ATTACKING && state != SHOOTING && clock.getElapsedTime().asSeconds() > 1) {
        clock.restart();
        state = ATTACKING;
    }
}
