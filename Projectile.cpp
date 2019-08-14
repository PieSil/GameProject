/**
 * Project Game
 */


#include "Projectile.h"

/**
 * Projectile implementation
 */



Projectile::Projectile(const float &x, const float &y, const bool &facingR, const bool &friendly, const float &movSpeed)
        : friendly(friendly), MovingEntity(x, y, movSpeed, facingR) {

}

Projectile::Projectile(Enemy *enemy, const float &movSpeed = PROJ_SPEED)
        : friendly(false), MovingEntity(enemy->getAllPositions().spritePosition.x, enemy->getAllPositions().spritePosition.y, movSpeed){
    facingRight = enemy->isFacingRight();
}

Projectile::Projectile(GameHero *hero, const float &movSpeed = PROJ_SPEED)
        : friendly(true), MovingEntity(hero->getAllPositions().spritePosition.x, hero->getAllPositions().spritePosition.y, movSpeed) {
    facingRight = hero->isFacingRight();
}


const EntityPositions Projectile::move(const float &distance) {

    EntityPositions prevPosition;

    if (this->facingRight)
        prevPosition = MovingEntity::move(Direction::RIGHT, distance);
    else
        prevPosition = MovingEntity::move(Direction::LEFT, distance);

    updatePositions();

    return prevPosition;

}