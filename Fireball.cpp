/**
 * Project Game
 */


#include "Fireball.h"

/**
 * Fireball implementation
 */

//TODO: complete implementation



Fireball::Fireball(const float &x, const float &y, const bool &facingR, const bool& friendly, const float &movSpeed) :
        Projectile(x, y, facingR, friendly, movSpeed) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());

}

const SpriteParams Fireball::fireballParams(FIREB_WIDTH, FIREB_HEIGHT, FIREB_HITBOX_X, FIREB_HITBOX_Y, FIREB_SCALE,
                                            FIREB_PATH, FIREB_IDLE_ROW,
                                            FIREB_IDLE_LAST_COL, FIREB_MOV_ROW, FIREB_MOV_LAST_COL, FIREB_ATT_ROW,
                                            FIREB_ATT_LAST_COL, 0, FIREB_SHOOT_ROW, FIREB_SHOOT_LAST_COL);

void Fireball::characterCollision(GameCharacter *character) {
    character->setOnFire(true);
}

void Fireball::destroy() {
    this->~Fireball();
}

const SpriteParams *Fireball::getParameters() const {
    return &fireballParams;
}
