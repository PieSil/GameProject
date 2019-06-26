#include <iostream>
#include <memory.h>
#include <SFML/Graphics.hpp>
#include "defaultValues.h"
#include "GameLevel.h"
#include "GameEntity.h"
#include "Knight.h"
#include "Wizard.h"
#include "Projectile.h"


int main(){
    GameLevel gameLevel;
    while(!(gameLevel.getWindow()->isClosed())) {

        gameLevel.handleInput();

        gameLevel.updateLevel();

        gameLevel.renderLevel();
    }
}