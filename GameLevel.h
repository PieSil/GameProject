/**
 * Project Game
 */


#ifndef _GAMELEVEL_H
#define _GAMELEVEL_H

#include "GameWindow.h"
#include "Wizard.h"
#include "Knight.h"
#include <memory>

class GameLevel {
public:
    explicit GameLevel (
            std::unique_ptr<GameWindow> w = std::move(std::unique_ptr<GameWindow>(new GameWindow("Level", sf::Vector2u(800,600))))
                    );
    ~GameLevel() {};

    void handleInput();
    void updateLevel();
    void renderLevel();


    const std::unique_ptr<GameWindow> &getWindow() const {
        return window;
    }

private:
    void moveHero();

    std::unique_ptr<GameHero> hero;
    std::unique_ptr<GameWindow> window;

};

#endif //_GAMELEVEL_H