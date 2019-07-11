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

}

Enemy::Enemy(const Enemy &copied) : hero(copied.getHero()), paralyzed(false), aggro(false),
                                    aggroRange(copied.getAggroRange()), GameCharacter(copied) {

}

const std::pair<bool, Hitbox> Enemy::attack(const bool &bypassClock) {

    std::pair<bool, Hitbox> result;

    result.first = false;

    if (!paralyzed)
        result = GameCharacter::attack();

    return  result;
}

const EntityPositions Enemy::move(const float &distance) {

    EntityPositions prevPosition;

    updateAggro();

    prevPosition = allPositions;

    if (!paralyzed && aggro && abs(hero->getSprite().getPosition().x - sprite.getPosition().x) >= attackRange) { //if enemy is not paralyzed and aggro is active

        if (facingRight) { //if enemy is facing right
            prevPosition = GameCharacter::move(RIGHT, distance); //move right

        } else {
            prevPosition = GameCharacter::move(LEFT, distance); //else move left
        }

    }

    return prevPosition;

}

void Enemy::updateAggro() {

    //if aggro is not activated and hero sprite is in aggro range
    // (if absolute value of hero x coordinate - enemy x coordinate is < aggro range then hero is in aggro range)
    if (!aggro && abs(hero->getSprite().getPosition().x - this->sprite.getPosition().x) <= aggroRange) {
        aggro = true; //activate aggro
    }

    if (hero->getSprite().getPosition().x <=
        this->sprite.getPosition().x) { //if hero is at enemy's left (hero x coordinate is < sprite x coordinate)
        facingRight = false; //turn left

    } else {
        facingRight = true; //else turn right
    }
}

const std::pair<bool, Hitbox> Enemy::updateCombat() {
    updateAggro();
    return attack();
}
