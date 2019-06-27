/**
 * Project Game
 */


#ifndef _GAMELEVEL_H
#define _GAMELEVEL_H

#include "defaultValues.h"
#include "GameWindow.h"
#include "Wizard.h"
#include "Knight.h"
#include <memory>

class Game {
public:
    explicit Game (
            std::unique_ptr<GameWindow> w = std::move(std::unique_ptr<GameWindow>(new GameWindow("Level", sf::Vector2u(800,600))))
                    );
    ~Game() {};

    void handleInput();
    void updateLevel();
    void renderLevel();


    const std::unique_ptr<GameWindow> &getWindow() const {
        return window;
    }

    const sf::Time &getElapsed() const {
        return elapsed;
    }

    void restartClock() {
        elapsed += clock.restart(); //restarts clock, adds elapsed time since last restart to elapsed attribute
    };



private:
    void moveHero(const Direction &direction);

    sf::Clock clock;
    sf::Time elapsed;
    float frameTime; //allows to use a fixed time-step to update the game

    std::unique_ptr<GameHero> hero;
    std::unique_ptr<GameWindow> window;

};

#endif //_GAMELEVEL_H