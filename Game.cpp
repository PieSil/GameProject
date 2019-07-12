/**
 * Project Game
 */


#include "Game.h"
#include "GameEntity.h"
#include "MovingEntity.h"
#include "GameState.h"
#include "PlayingState.h"
#include "SelectionState.h"

/**
 * Game implementation
 */

std::unique_ptr<Game> Game::gameInstance(nullptr);

const bool Game::createGame() {

    bool created = false;

    if (!gameInstance) {
        gameInstance.reset(new Game(std::unique_ptr<GameWindow>(new GameWindow("Game", sf::Vector2u(TILE_SIZE.x * 5 * 10, TILE_SIZE.y * 8 * 10)))));
        created = true;
    }

    return created;
}

Game *Game::getGame() {
    return gameInstance.get();
}

Game::Game(std::unique_ptr<GameWindow> w) : frameTime(1. / FRAMERATE), window(std::move(w)) {

    createView();
    setState(State::SELECTION);

}

void Game::updateGame() {
    if (elapsed.asSeconds() >= frameTime) { //game updates ony if elapsed time is >= than fixed time-step chosen

    getCurrentState()->update();

    //game updated, subtract fixed time-step and "reset" elapsed time
    //game will update again when elapsed equals the fixed time-step chosen
    elapsed -= sf::seconds(frameTime);
}

    window->update();
}

    void Game::renderLevel() const {
        //clears window:
        window->beginDraw();

        //draws on window
        getCurrentState()->draw();

        //displays window:
        window->endDraw();
    }

    void Game::pushState(State state, Herotype heroT) {
        switch (state) {

            case State::PLAYING:
                states.emplace(new PlayingState(this, heroT));
                break;

            case State::SELECTION:
                states.emplace(new SelectionState(this));
                break;

            default:
                states.emplace(new SelectionState(this));
                break;
        }

    }

void Game::popState() {
    delete(states.top());
    states.pop();
}

void Game::setState(State state, Herotype heroT) {

    if (!states.empty())
        popState();

    pushState(state, heroT);
}

GameState *Game::getCurrentState() const {
    if (!states.empty())
        return states.top();

    else
        return nullptr;
}

void Game::createView() {
    view.reset(new sf::View(sf::View(sf::Vector2f(window->getWindowSize().x, window->getWindowSize().y), sf::Vector2f(8 * TILE_SIZE.x, 8 * TILE_SIZE.y))));
    window->setView(*view);
}


