/**
 * Project Game
 */


#include "Enemy.h"

/**
 * Enemy implementation
 */
Enemy::Enemy(GameHero *hero, const float &x, const float &y, const float &str, const bool &par, const bool &onf,
             const float &h, const bool &facingR, const float &s)
             : hero (hero), paralyzed(par), aggro(false), aggroRange(100), GameCharacter(x, y, str, onf, h, s, facingR) {

    hero->registerObserver(this);

}

Enemy::Enemy(const Enemy &copied) : hero(copied.getHero()), paralyzed(false), aggro(false), GameCharacter(copied) {
    hero->registerObserver(this);
}

void Enemy::attack() {
    if (!paralyzed)
        GameCharacter::attack();
}

void Enemy::move(const Direction &direction, const float &distance) {
    if (!paralyzed)
        MovingEntity::move(direction, distance);
}

void Enemy::update(const sf::Sprite &sprite) {
    this->heroSprite = sprite;
}
