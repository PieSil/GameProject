//
// Created by Pietro on 2019-07-13.
//

#ifndef GAMEPROJECT_GAMEOVER_H
#define GAMEPROJECT_GAMEOVER_H

#include "GameState.h"

class GameOver : public GameState {
public:
    explicit GameOver(Game *game);

    ~GameOver() override;

    void update() override;

    void draw() override;

    void handleInput() override;
};


#endif //GAMEPROJECT_GAMEOVER_H
