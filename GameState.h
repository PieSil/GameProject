//
// Created by Pietro on 2019-07-12.
//

#ifndef GAMEPROJECT_GAMESTATE_H
#define GAMEPROJECT_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class GameState {
public:
    explicit GameState(Game *game);

    virtual ~GameState() {};

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void handleInput() = 0;

    GameState(const GameState&) = delete;
    GameState&operator=(const GameState&) = delete;
protected:
    Game* game;

};


#endif //GAMEPROJECT_GAMESTATE_H
