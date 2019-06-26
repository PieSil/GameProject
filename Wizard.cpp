/**
 * Project Game
 */


#include "Wizard.h"

/**
 * Wizard implementation
 */
void Wizard::specialBehaviour() {

}

Wizard::Wizard(float x, float y, float str, bool onf, float m, float h, bool facingR, float s)
               : GameHero(x, y, str, onf, h, facingR, s), mana(m){
    this->initSprite(x,y);
}

void Wizard::updateBehaviour() {
    GameHero::updateBehaviour(WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_MOV_ROW_SELECTOR, WIZARD_MOV_LAST_COL);
}

void Wizard::initSprite(float x, float y) {
    loadTexture("../GameAssets/Sprites/Player/Wizard/Wizard.png");
    sprite.setTextureRect(sf::IntRect(0,WIZARD_HEIGHT*1,WIZARD_WIDTH,WIZARD_HEIGHT*1));
    //sets origin to center of selected texture Rectangle
    sprite.setOrigin(sprite.getTextureRect().width/2., sprite.getTextureRect().height/2.);
    //initializes knight sprite position
    sprite.setPosition(x,y);
    if (facingRight) {
        sprite.setScale(WIZARD_SCALE*1.f,WIZARD_SCALE*1.f);
    } else {
        sprite.setScale(-WIZARD_SCALE*1.f,WIZARD_SCALE*1.f);
    }

}

Wizard::Wizard() : Wizard(0,0) {

}

Wizard::Wizard(Wizard &copied) : GameHero(copied){
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
}
