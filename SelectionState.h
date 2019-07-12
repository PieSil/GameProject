//
// Created by Pietro on 2019-07-12.
//

#ifndef GAMEPROJECT_SELECTIONSTATE_H
#define GAMEPROJECT_SELECTIONSTATE_H

#include "GameState.h"

class SelectionState : public GameState {

public:
    explicit SelectionState(Game *game);

    ~SelectionState() {};

    void update() override;

    void draw() override;

    void handleInput() override;
};


#endif //GAMEPROJECT_SELECTIONSTATE_H
