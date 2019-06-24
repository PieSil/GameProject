/**
 * Project Game
 */


#include "Wizard.h"

/**
 * Wizard implementation
 */
void Wizard::specialBehaviour() {

}

Wizard::Wizard(float x, float y, bool onf, float m, float h, bool facingR, float s)
               : GameHero(x, y, onf, h, facingR, s), mana(m){
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

void Wizard::updateMovement() {
    GameHero::updateMovement(WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_MOV_ROW_SELECTOR, WIZARD_MOV_LAST_COL);
}
