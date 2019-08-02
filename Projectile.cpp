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

Projectile::Projectile(const Hitbox &hitbox, Enemy *enemy, const float &movSpeed = PROJ_SPEED)
        : friendly(false), MovingEntity(hitbox.getHitbox().getPosition().x, hitbox.getHitbox().getPosition().y, movSpeed){
    facingRight = enemy->isFacingRight();
}

Projectile::Projectile(const Hitbox &hitbox, GameHero *hero, const float &movSpeed = PROJ_SPEED)
        : friendly(true), MovingEntity(hitbox.getHitbox().getPosition().x, hitbox.getHitbox().getPosition().y, movSpeed) {
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