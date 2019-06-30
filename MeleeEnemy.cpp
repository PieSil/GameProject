/**
 * Project Game
 */


#include "MeleeEnemy.h"

/**
 * MeleeEnemy implementation
 */

const SpriteParams MeleeEnemy::meleeParams(MELEE_WIDTH, MELEE_HEIGHT, MELEE_HITBOX_X, MELEE_HITBOX_Y, MELEE_SCALE,
                                           MELEE_PATH, MELEE_IDLE_ROW,
                                           MELEE_IDLE_LAST_COL, MELEE_MOV_ROW, MELEE_MOV_LAST_COL);


MeleeEnemy::MeleeEnemy(GameHero *hero, const float &x, const float &y, const float &str, const bool &par, const bool &onf,
                       const float &h, const bool &facingR, const float &s) : GameCharacter(x, y, str, onf, h, s, facingR), Enemy(hero, x, y) {

    initSprite(x, y);
    giveHitbox();

}

MeleeEnemy::MeleeEnemy(const MeleeEnemy &copied) : GameCharacter(copied), Enemy(copied) {
    this->aggro = false;
    this->paralyzed = false;
}

MeleeEnemy &MeleeEnemy::operator=(const MeleeEnemy &meleeEnemy) {
    this->hero = meleeEnemy.getHero();
    this->hero->registerObserver(this);
    this->aggro = false;
    this->paralyzed = false;
    return *this;
}
