/**
 * Project Game
 */


#include "MeleeEnemy.h"

/**
 * MeleeEnemy implementation
 */
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



void MeleeEnemy::giveHitbox() {
    GameEntity::giveHitbox(sprite.getPosition(), sprite.getTextureRect().width, sprite.getTextureRect().height, MELEE_HITBOX_X, MELEE_HITBOX_Y,
                           MELEE_SCALE);
}

void MeleeEnemy::initSprite(const float &x, const float &y) {
    MovingEntity::initSprite(x,y, MELEE_PATH, MELEE_WIDTH, MELEE_HEIGHT, MELEE_SCALE, MELEE_IDLE_ROW, MELEE_IDLE_COL);
}

void MeleeEnemy::move(const Direction& direction, const float& distance) {
    Enemy::moveOnX(direction, distance, MELEE_WIDTH, MELEE_HEIGHT, MELEE_SCALE, MELEE_MOV_ROW, MELEE_MOV_LAST_COL);
}

MeleeEnemy &MeleeEnemy::operator=(const MeleeEnemy &meleeEnemy) {
    this->aggro = false;
    this->paralyzed = false;
    return *this;
}
