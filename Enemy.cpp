/**
 * Project Game
 */


#include "Enemy.h"

/**
 * Enemy implementation
 */
Enemy::Enemy(GameHero *hero, const float &x, const float &y, const float &str, const bool &par, const bool &onf,
             const float &h, const bool &facingR, const float &s)
        : hero(hero), paralyzed(par), aggro(false), aggroRange(100), GameCharacter(x, y, str, onf, h, s, facingR) {

    hero->registerObserver(this);

}

Enemy::Enemy(const Enemy &copied) : hero(copied.getHero()), paralyzed(false), aggro(false), GameCharacter(copied) {
    hero->registerObserver(this);
}

const float & Enemy::attack() {
    if (!paralyzed)
        return GameCharacter::attack();
    else
        return strength;
}

void Enemy::move(const float &distance) {
    if (!paralyzed && aggro) { //if enemy is not paralyzed and aggro is active

        if (facingRight) { //if enemy is facing right
            MovingEntity::move(RIGHT, distance); //move right

        } else {
            MovingEntity::move(LEFT, distance); //else move left
        }
    }

}

void Enemy::update(const sf::Sprite &sprite) {
    this->heroSprite = sprite;
    updateAggro();
}

void Enemy::updateAggro() {

    //if aggro is not activated and hero sprite is in aggro range
    // (if absolute value of hero x coordinate - enemy x coordinate is < aggro range then hero is in aggro range)
    if (!aggro && abs(heroSprite.getPosition().x - this->sprite.getPosition().x) <= aggroRange) {
        aggro = true; //activate aggro
    }

    if(heroSprite.getPosition().x <= this->sprite.getPosition().x) { //if hero is at enemy's left (hero x coordinate is < sprite x coordinate)
        facingRight = false; //turn left

    } else {
        facingRight = true; //else turn right
    }
}
