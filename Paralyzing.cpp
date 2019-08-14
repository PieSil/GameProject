/**
 * Project Game
 */


#include "Paralyzing.h"

/**
 * Paralyzing implementation
 */

const SpriteParams Paralyzing::paralyzingParams(
        PARA_PATH, PARA_WIDTH, PARA_HEIGHT, PARA_SCALE, PARA_HITBOX_X, PARA_HITBOX_Y, PARA_IDLE_ROW,
        PARA_IDLE_LAST_COL, PARA_MOV_ROW, PARA_MOV_LAST_COL);

Paralyzing::Paralyzing(const float &x, const float &y, const bool &facingR, const bool& friendly, const float &movSpeed) :
            Projectile(x, y, facingR, friendly, movSpeed) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());

}

Paralyzing::Paralyzing(GameHero *hero, const float &movSpeed) : Projectile(hero, movSpeed) {
    initSprite(hero->getAllPositions().spritePosition.x, hero->getAllPositions().spritePosition.y);
    giveHitbox();
    setupAnimations(getParameters());
}

void Paralyzing::characterCollision(GameCharacter *character) {

    if (auto enemy = dynamic_cast<Enemy*>(character)) {

        if (!enemy->isParalyzed()) { //paralyze enemy if not already paralyzed
            enemy->setParalyzed(true);
            enemy->getClocks().paralyzedClock.restart();
        }

    }
}
