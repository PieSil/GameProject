/**
 * Project Game
 */


#include "Fireball.h"

/**
 * Fireball implementation
 */

const SpriteParams Fireball::fireballParams(
        FIREB_PATH, FIREB_WIDTH, FIREB_HEIGHT, FIREB_SCALE, FIREB_HITBOX_X, FIREB_HITBOX_Y, FIREB_IDLE_ROW,
        FIREB_IDLE_LAST_COL, FIREB_MOV_ROW, FIREB_MOV_LAST_COL);

Fireball::Fireball(const float &x, const float &y, const bool &facingR, const bool& friendly, const float &movSpeed) :
        Projectile(x, y, facingR, friendly, movSpeed) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());

}

Fireball::Fireball(const Hitbox &hitbox, Enemy *enemy, const float &movSpeed) : Projectile(hitbox, enemy, movSpeed) {
    initSprite(hitbox.getHitbox().getPosition().x, hitbox.getHitbox().getPosition().y);
    giveHitbox();
    setupAnimations(getParameters());
}

Fireball::Fireball(const Hitbox &hitbox, GameHero *hero, const float &movSpeed) : Projectile(hitbox, hero, movSpeed) {
    initSprite(hitbox.getHitbox().getPosition().x, hitbox.getHitbox().getPosition().y);
    giveHitbox();
    setupAnimations(getParameters());
}

void Fireball::characterCollision(GameCharacter *character) {
    if (!character->isOnFire()) {
        character->getClocks().burnClock.restart();
        character->setOnFire(true);
    }
}

const SpriteParams *Fireball::getParameters() const {
    return &fireballParams;
}
