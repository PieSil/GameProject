/**
 * Project Game
 */


#include "Knight.h"
#include "defaultValues.h"
/**
 * Knight implementation
 */

Knight::Knight(float x, float y, bool onf, float h, bool facingR, float s) : GameHero(x, y, onf, h, facingR, s) {
    this->initSprite(x,y);
}

void Knight::specialBehaviour() {

}

void Knight::updateBehaviour() {
    GameHero::updateBehaviour(KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_SCALE, KNIGHT_MOV_ROW_SELECTOR, KNIGHT_MOV_LAST_COL);
}

Knight::Knight() : Knight(0,0) {

}

Knight::Knight(const Knight &copied) : GameHero(copied){
    this->initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
}

void Knight::initSprite(float x, float y) {
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


