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

    Herotype hero;
do {
    std::cout << "\nPress \"k\" to select Knight, press \"w\" to select Wizard" << std::endl;

    std::cin >> hero;

} while (hero != KNGT && hero != WZRD);

    Game game(hero);

    //Game Loop
    while(!(game.getWindow()->isClosed())) {

        game.updateGame();

        game.renderLevel();

        game.restartClock();

    }
}