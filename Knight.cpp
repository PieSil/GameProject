/**
 * Project Game
 */


#include "Knight.h"
#include "defaultValues.h"
/**
 * Knight implementation
 */

Knight::Knight(int x, int y, bool onf, float h, bool facingR) : GameHero(x, y, onf, h, facingR) {
    loadTexture("../GameAssets/Sprites/Player/Knight/Knight.png");
    sprite.setTextureRect(sf::IntRect(0,KNIGHT_HEIGHT*1,KNIGHT_WIDTH,KNIGHT_HEIGHT*1));
    if (facingRight) {
        sprite.setScale(KNIGHT_SCALE*1.f,KNIGHT_SCALE*1.f);
    } else {
        sprite.setScale(-KNIGHT_SCALE*1.f,KNIGHT_SCALE*1.f);
    }
}

void Knight::specialBehaviour() {

}

void Knight::updateMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(HERO_SPEED, 0);
        sprite.setTextureRect(sf::IntRect(KNIGHT_WIDTH*movingCounter,KNIGHT_HEIGHT*4,KNIGHT_WIDTH,KNIGHT_HEIGHT));
        if (!facingRight) {
            sprite.setScale(KNIGHT_SCALE*1.f,KNIGHT_SCALE*1.f);
            facingRight = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-HERO_SPEED, 0);
        sprite.setTextureRect(sf::IntRect(KNIGHT_WIDTH*movingCounter,KNIGHT_HEIGHT*4,KNIGHT_WIDTH,KNIGHT_HEIGHT));
        if (facingRight) {
            sprite.setScale(-KNIGHT_SCALE*1.f,KNIGHT_SCALE*1.f);
            facingRight = false;
        }
    }

    movingCounter++;

    if (movingCounter > 7)
        movingCounter = 0;
}


