/**
 * Project Game
 */


#include "Heart.h"

/**
 * Heart implementation
 */

const SpriteParams Heart::heartParams(HEART_PATH, HEART_WIDTH, HEART_HEIGHT, HEART_SCALE, 1, 1, HEART_IDLE_ROW, HEART_IDLE_LAST_COL);

Heart::Heart(GameHero *hero, const float &x, const float &y, const float &heal) : Collectible(x, y), hero(hero), heal(heal) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());
}

Heart::~Heart() {
}



void Heart::characterCollision(GameCharacter *character) {
    if (character->getState() != EntityState::DYING && character->getState() != EntityState::DEAD) {
        float newHealth = character->getHealth() + heal;

        //avoid setting health to a value bigger than default value
        if (newHealth >= DEF_HERO_HEALTH)
            newHealth = DEF_HERO_HEALTH;

        character->setHealth(newHealth);
    }
}

const bool Heart::updateBehaviour() {
    bool toDestroy = false;

    if (hero->getHitbox().checkHitbox().intersects(this->hitbox.checkHitbox())) {
        characterCollision(hero);
        toDestroy = true;
    }

    return toDestroy;
}
