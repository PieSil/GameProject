/**
 * Project Game
 */


#ifndef _GAMELEVEL_H
#define _GAMELEVEL_H

#include "gameValues.h"
#include "entityPositions.h"
#include "GameWindow.h"
#include "Wizard.h"
#include "Knight.h"
#include "MeleeEnemy.h"
#include "RangedEnemy.h"
#include "BossEnemy.h"
#include "Map.h"
#include "GameLevel.h"
#include <stack>
#include <memory>
#include <iostream>
#include <list>

class GameState;

enum class State {
    SELECTION, PLAYING, GAMEOVER, VICTORY
};

class Game {

public:

    ~Game() {};

    void updateGame();
    void renderLevel() const;

    void restartClock() {
        elapsed += clock.restart(); //restarts clock, adds elapsed time since last restart to elapsed attribute
    };


    static const bool createGame();

    static Game* getGame();

    void createViews();

    void pushState(State state, Herotype heroT = Herotype::KNGT);

    void popState();

    void setState(State state, Herotype heroT = Herotype::KNGT);

    GameState* getCurrentState() const;

    const std::unique_ptr<GameWindow> &getWindow() const {
        return window;
    }

    const std::unique_ptr<sf::View> &getPlayerView() const {
        return playerView;
    }

    const std::unique_ptr<sf::View> &getHudView() const {
        return hudView;
    }

    const sf::Time &getElapsed() const {
        return elapsed;
    }

    void setElapsed(const sf::Time &elapsed) {
        Game::elapsed = elapsed;
    }

    float getFrameTime() const {
        return frameTime;
    }

    //disable copy and assignment
    Game(const Game&) = delete;
    Game&operator=(const Game&) = delete;

private:

    explicit Game(std::unique_ptr<GameWindow> w);

    std::stack<GameState*> states;

    sf::Clock clock;
    sf::Time elapsed;
    float frameTime; //allows to use a fixed time-step to update the game

    std::unique_ptr<GameWindow> window;
    std::unique_ptr<sf::View> playerView;
    std::unique_ptr<sf::View> hudView;

    static std::unique_ptr<Game> gameInstance;

};

#endif //_GAMELEVEL_H