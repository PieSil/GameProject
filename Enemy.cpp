/**
 * Project Game
 */


#include "Enemy.h"

/**
 * Enemy implementation
 */
Enemy::Enemy(const float &x, const float &y, const float &str, const bool &par, const bool &onf, const float &h,
             const bool &facingR,
             const float &s) : paralyzed(par), aggro(false),  GameCharacter(x, y, str, onf, h, s, facingR) {

}

Enemy::Enemy() : Enemy(0, 0) {

}

Enemy::Enemy(const Enemy &copied) : paralyzed(false), aggro(false), GameCharacter(copied) {

}

Enemy::~Enemy () {}

void Enemy::attack() {
    if (!paralyzed)
        GameCharacter::attack();
}

void Enemy::moveOnX(const Direction &direction, const float &distance, const int &width, const int &height,
                    const float &scale, const int &row, const int &lastColumn) {
    if (!paralyzed)
        MovingEntity::moveOnX(direction, distance, width, height, scale, row, lastColumn);

}

void Enemy::moveOnY(const float &height, const Direction &direction) {
    if (!paralyzed)
        MovingEntity::moveOnY(height, direction);
}
