/**
 * Project Game
 */


#include "Wizard.h"

/**
 * Wizard implementation
 */
void Wizard::specialBehaviour() {

}

Wizard::Wizard(const float &x, const float &y, const float &str, const bool &onf, const float &m, const float &h,
               const bool &facingR, const float &s)
               : GameHero(x, y, str, onf, h, facingR, s), mana(m){
    initSprite(x, y);
    giveHitbox();
}

/*
void Wizard::updateBehaviour() {
    GameHero::updateBehaviour(WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_MOV_ROW_SELECTOR, WIZARD_MOV_LAST_COL);
}
 */

void Wizard::initSprite(const float &x, const float &y, const std::string &path, const int &width, const int &height,
                        const float &scale, const int &row, const int &column) {
    initSprite(x,y);
}

Wizard::Wizard() : Wizard(0,0) {

}

Wizard::Wizard(Wizard &copied) : GameHero(copied){
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}

void Wizard::move(const Direction &direction, const float& distance) {
    GameEntity::move(direction,  distance, WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_MOV_ROW_SELECTOR, WIZARD_MOV_LAST_COL);
}

void Wizard::initSprite(const float& x, const float& y) {
    GameEntity::initSprite(x,y, WIZARD_PATH, WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_IDLE_ROW, WIZARD_IDLE_COL);
}

void Wizard::giveHitbox() {
    GameEntity::giveHitbox(WIZARD_HITBOX_X, WIZARD_HITBOX_Y, WIZARD_SCALE);
}
