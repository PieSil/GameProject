#include <iostream>
#include <memory.h>
#include <SFML/Graphics.hpp>
#include "defaultValues.h"
#include "Game.h"
#include "GameEntity.h"
#include "Knight.h"
#include "Wizard.h"
#include "Projectile.h"

 
int main(){
    Game gameLevel;

    //Game Loop
    while(!(gameLevel.getWindow()->isClosed())) {

        gameLevel.handleInput();

        gameLevel.updateLevel();

        gameLevel.renderLevel();

        gameLevel.restartClock();

    }
}