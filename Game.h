/**
 * Project Game
 */


#ifndef _GAMELEVEL_H
#define _GAMELEVEL_H

#include "gameValues.h"
#include "positionsStruct.h"
#include "GameWindow.h"
#include "Wizard.h"
#include "Knight.h"
#include "MeleeEnemy.h"
#include "RangedEnemy.h"
#include "BossEnemy.h"
#include "Map.h"
#include <memory>
#include <iostream>
#include <list>

class Game {
public:

    //TODO: delegate hero selction to other class, not the game constructor
    explicit Game (
            Heroytype heroT = 0,
            std::unique_ptr<GameWindow> w = std::move(std::unique_ptr<GameWindow>(new GameWindow("Level", sf::Vector2u(8*TILE_SIZE.x * 5,8*TILE_SIZE.y * 5))))
                    );
    ~Game() {};

    void handleInput();
    void updateGame();
    void renderLevel() const;

    void drawHitbox(const Hitbox &hitbox) const;


    const std::unique_ptr<GameWindow> &getWindow() const {
        return window;
    }

    const sf::Time &getElapsed() const {
        return elapsed;
    }

    void restartClock() {
        elapsed += clock.restart(); //restarts clock, adds elapsed time since last restart to elapsed attribute
    };


    //disable copy and assignment
    Game(const Game&) = delete;
    Game&operator=(const Game&) = delete;

private:
    void updatePhysics(GameCharacter* character);

    void checkOnGround(GameCharacter* character);

    void moveHero(const Direction &direction);

    void detectCollisions(const entityPositions prevPosition, GameCharacter *character);

    void resolveCollisions();

    void updateEnemies();

    void createView();

    void updateView();

    void createMap();

    sf::Clock clock;
    sf::Time elapsed;
    float frameTime; //allows to use a fixed time-step to update the game

    std::unique_ptr<GameHero> hero;
    std::list<std::unique_ptr<Enemy>> enemies;
    std::unique_ptr<GameWindow> window;
    std::shared_ptr<sf::View> view;

    Map gameMap;

    entityPositions positions;

};

#endif //_GAMELEVEL_H