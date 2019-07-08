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

void Enemy::attack() {
    if (!paralyzed)
        GameCharacter::attack();
}

const entityPositions Enemy::move(const float &distance) {

    entityPositions prevPosition;

    updateAggro();

    prevPosition = allPositions;

    if (!paralyzed && aggro && abs(hero->getSprite().getPosition().x - sprite.getPosition().x) >= 16) { //if enemy is not paralyzed and aggro is active

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

const entityPositions Enemy::updateBehaviour(const float& distance) {
    updateAggro();
    attack();
    auto prevPosition = move(distance);
    return prevPosition;

}
