/**
 * Project Game
 */


#include "Wizard.h"
#include "MovingEntity.h"
#include "GameEntity.h"

/**
 * Wizard implementation
 */


const SpriteParams Wizard::wizardParams(WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_HITBOX_X, WIZARD_HITBOX_Y, WIZARD_SCALE,
                                        WIZARD_PATH, WIZARD_IDLE_ROW,
                                        WIZARD_IDLE_LAST_COL, WIZARD_MOV_ROW, WIZARD_MOV_LAST_COL, WIZARD_ATT_ROW,
                                        WIZARD_ATT_LAST_COL, WIZARD_ATT_OFFSET, WIZARD_SHOOT_ROW, WIZARD_SHOOT_LAST_COL);

void Wizard::specialBehaviour() {

}

Wizard::Wizard(const float &x, const float &y, const float &str, const bool &onf, const float &m, const float &h,
               const bool &facingR, const float &s)
        : GameHero(x, y, str, onf, h, facingR, s), mana(m) {
    initSprite(x, y);
    giveHitbox();
    GameCharacter::setupAnimations(getParameters());
    setAttackBehaviour(new ShootingBehaviour);
}

/*
void Wizard::updateBehaviour() {
    GameHero::updateBehaviour(WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_MOV_ROW, WIZARD_MOV_LAST_COL);
}
 */

Wizard::Wizard() : Wizard(0, 0) {

}

Wizard::Wizard(const Wizard &copied) : mana(copied.getMana()), GameHero(copied) {
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}