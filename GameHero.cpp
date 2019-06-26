/**
 * Project Game
 */


#include "GameHero.h"
#include "defaultValues.h"

/**
 * GameHero implementation
 */

GameHero::GameHero(const float &x, const float &y, const float &str, const bool &onf, const float &h,
                   const bool &facingR, const float &s) : GameCharacter(x, y, str, onf, h, s, facingR) {

}

void GameHero::updateMovement(int width, int height, float scale, int rowSelector, int lastColumn) {

    //move right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(this->movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(width * movingCounter, height * rowSelector, width, height));
        if (!facingRight) { //flip horizontally
            sprite.setScale(scale * 1.f, scale * 1.f);
            facingRight = true;
        }
    }

    //move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-(this->movementSpeed), 0);
        sprite.setTextureRect(sf::IntRect(width * movingCounter, height * rowSelector, width, height));
        if (facingRight) { //flip horizontally
            sprite.setScale(scale * (-1.f), scale * 1.f);
            facingRight = false;
        }
    }


        movingCounter++;

        if (movingCounter > lastColumn) {
            movingCounter = 0;
        }
}

GameHero::GameHero() : GameHero(0,0) {

}

GameHero::GameHero(const GameHero &copied) : GameCharacter(copied) {

}

void GameHero::updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) {
    this->updateMovement(width, height, scale, rowSelector, lastColumn);
}
