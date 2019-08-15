//
// Created by Pietro on 2019-07-13.
//

#include "SelectionState.h"
#include "GameOver.h"

GameOver::GameOver(Game *game) : GameState(game) {
    game->getWindow()->setView(*game->getPlayerView());

}

GameOver::~GameOver() {

}

void GameOver::update() {
    game->setState(State::SELECTION);
}

void GameOver::draw() {

}

void GameOver::handleInput() {

}
