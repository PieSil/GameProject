/**
 * Project Game
 */


#include "Wizard.h"
#include "MovingEntity.h"
#include "GameEntity.h"

/**
 * Wizard implementation
 */
void Wizard::specialBehaviour() {

}

Wizard::Wizard(const float &x, const float &y, const float &str, const bool &onf, const float &m, const float &h,
               const bool &facingR, const float &s)
               : GameCharacter(x, y ,str ,onf ,h ,s ,facingR),  mana(m) {
    initSprite(x, y);
    giveHitbox();
}

/*
void Wizard::updateBehaviour() {
    GameHero::updateBehaviour(WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_MOV_ROW_SELECTOR, WIZARD_MOV_LAST_COL);
}
 */

Wizard::Wizard() : Wizard(0,0) {

}

Wizard::Wizard(const Wizard &copied) : ShootingCharacter(copied), GameHero(copied) {
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}

void Wizard::move(const Direction &direction, const float& distance) {
    MovingEntity::moveOnX(direction, distance, WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_MOV_ROW_SELECTOR,
                        WIZARD_MOV_LAST_COL);
}

void Wizard::initSprite(const float& x, const float& y) {
    MovingEntity::initSprite(x,y, WIZARD_PATH, WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_IDLE_ROW, WIZARD_IDLE_COL);
}

void Wizard::giveHitbox() {
    GameEntity::giveHitbox(sprite.getPosition(), sprite.getTextureRect().width, sprite.getTextureRect().height, WIZARD_HITBOX_X, WIZARD_HITBOX_Y,
                           WIZARD_SCALE);
}
