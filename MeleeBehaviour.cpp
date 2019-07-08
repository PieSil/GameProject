//
// Created by Pietro on 2019-07-08.
//

#include "MeleeBehaviour.h"

void MeleeBehaviour::attack(State &state) {

    if (state != ATTACKING && state != SHOOTING) {
        state = ATTACKING;
    }

}
