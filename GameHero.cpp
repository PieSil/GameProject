/**
 * Project Game
 */


#include "GameHero.h"
#include "defaultValues.h"

/**
 * GameHero implementation
 */

const float GameHero::defHealth = DEF_GAMEHERO_HEALTH;

GameHero::GameHero(float x, float y, bool onf, float h, bool facingR, float s) : GameCharacter(x, y, onf, h, s, facingR) {

}

void GameHero::updateMovement(int width, int height, float scale) {

    //move right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(this->movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(width * movingCounter, height * 4, width, height));
        if (!facingRight) { //flip horizontally
            sprite.setScale(scale * 1.f, scale * 1.f);
            facingRight = true;
        }
    }

    //move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-(this->movementSpeed), 0);
        sprite.setTextureRect(sf::IntRect(width * movingCounter, height * 4, width, height));
        if (facingRight) { //flip horizontally
            sprite.setScale(scale * (-1.f), scale * 1.f);
            facingRight = false;
        }
    }


        movingCounter++;

        if (movingCounter > 7) {
            movingCounter = 0;
        }
}
