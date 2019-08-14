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

Fireball::Fireball(Enemy *enemy, const float &movSpeed) : Projectile(enemy, movSpeed) {
    initSprite(enemy->getAllPositions().spritePosition.x, enemy->getAllPositions().spritePosition.y);
    giveHitbox();
    setupAnimations(getParameters());
}

Fireball::Fireball(GameHero *hero, const float &movSpeed) : Projectile(hero, movSpeed) {
    initSprite(hero->getAllPositions().spritePosition.x, hero->getAllPositions().spritePosition.y);
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
