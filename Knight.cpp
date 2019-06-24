/**
 * Project Game
 */


#include "Knight.h"
#include "defaultValues.h"
/**
 * Knight implementation
 */

Knight::Knight(float x, float y, bool onf, float h, bool facingR, float s) : GameHero(x, y, onf, h, facingR, s) {
    loadTexture("../GameAssets/Sprites/Player/Knight/Knight.png");
    sprite.setTextureRect(sf::IntRect(0,KNIGHT_HEIGHT*1,KNIGHT_WIDTH,KNIGHT_HEIGHT*1));
    //sets origin to center of selected texture Rectangle
    sprite.setOrigin(sprite.getTextureRect().width/2., sprite.getTextureRect().height/2.);
    //initializes knight sprite position
    sprite.setPosition(x,y);
    if (facingRight) {
        sprite.setScale(KNIGHT_SCALE*1.f,KNIGHT_SCALE*1.f);
    } else {
        sprite.setScale(-KNIGHT_SCALE*1.f,KNIGHT_SCALE*1.f);
    }
}

void Knight::specialBehaviour() {

}

void Knight::updateMovement() {

    GameHero::updateMovement(KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_SCALE);
    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(KNIGHT_WIDTH*movingCounter,KNIGHT_HEIGHT*4,KNIGHT_WIDTH,KNIGHT_HEIGHT));
        if (!facingRight) {
            sprite.setScale(KNIGHT_SCALE*1.f,KNIGHT_SCALE*1.f);
            facingRight = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(KNIGHT_WIDTH*movingCounter,KNIGHT_HEIGHT*4,KNIGHT_WIDTH,KNIGHT_HEIGHT));
        if (facingRight) {
            sprite.setScale(-KNIGHT_SCALE*1.f,KNIGHT_SCALE*1.f);
            facingRight = false;
        }
    }

    movingCounter++;

    if (movingCounter > 7)
        movingCounter = 0;
        */
}


