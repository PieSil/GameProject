/**
 * Project Game
 */


#include "MeleeEnemy.h"

/**
 * MeleeEnemy implementation
 */

const SpriteParams MeleeEnemy::meleeParams(MELEE_WIDTH, MELEE_HEIGHT, MELEE_HITBOX_X, MELEE_HITBOX_Y, MELEE_SCALE,
                                        MELEE_PATH, MELEE_IDLE_ROW,
                                        MELEE_IDLE_COL, MELEE_MOV_ROW, MELEE_MOV_LAST_COL);


MeleeEnemy::MeleeEnemy(const float &x, const float &y, const float &str, const bool &par, const bool &onf,
                       const float &h, const bool &facingR, const float &s) : GameCharacter(x, y ,str ,onf ,h ,s ,facingR) {
    aggro = false;
    initSprite(x,y);
    giveHitbox();

}

MeleeEnemy::MeleeEnemy() : MeleeEnemy(0,0) {

}

MeleeEnemy::MeleeEnemy(const MeleeEnemy &copied) : GameCharacter(copied) {
    this->aggro = false;
    this->paralyzed = false;
}

MeleeEnemy &MeleeEnemy::operator=(const MeleeEnemy &meleeEnemy) {
    this->aggro = false;
    this->paralyzed = false;
    return *this;
}
