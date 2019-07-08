//
// Created by Pietro on 2019-07-08.
//

#ifndef GAMEPROJECT_MELEEBEHAVIOUR_H
#define GAMEPROJECT_MELEEBEHAVIOUR_H

#include "AttackBehaviour.h"

class MeleeBehaviour : public AttackBehaviour {
public:

    MeleeBehaviour() = default;

    ~MeleeBehaviour() {};

    void attack(State &state) override;
};


#endif //GAMEPROJECT_MELEEBEHAVIOUR_H
