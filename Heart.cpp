/**
 * Project Game
 */


#include "Heart.h"

/**
 * Heart implementation
 */
Heart::Heart(const float &x, const float &y, GameHero *hero, const float &heal) : Collectible(x, y) {

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
