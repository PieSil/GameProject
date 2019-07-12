#include <iostream>
#include <memory.h>
#include <SFML/Graphics.hpp>
#include "gameValues.h"
#include "Game.h"
#include "GameEntity.h"
#include "Knight.h"
#include "Wizard.h"
#include "Projectile.h"

 
int main(){

    if (Game::createGame()) {

        //Game Loop
        while (!(Game::getGame()->getWindow()->isClosed())) {

            Game::getGame()->updateGame();

            Game::getGame()->renderLevel();

            Game::getGame()->restartClock();

        }
    }
}