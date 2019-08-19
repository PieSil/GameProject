/**
 * Project Game
 */


#include "RangedEnemy.h"

/**
 * RangedEnemy implementation
 */

const SpriteParams RangedEnemy::rangedParams(RANGED_PATH, RANGED_WIDTH, RANGED_HEIGHT, RANGED_SCALE, RANGED_HITBOX_X,
                                             RANGED_HITBOX_Y, RANGED_IDLE_ROW, RANGED_IDLE_LAST_COL, RANGED_MOV_ROW,
                                             RANGED_MOV_LAST_COL, RANGED_ATT_ROW, RANGED_ATT_LAST_COL,
                                             RANGED_ATT_OFFSET, RANGED_SHOOT_ROW, RANGED_SHOOT_LAST_COL,
                                             RANGED_DEATH_ROW, RANGED_DEATH_LAST_COL);

RangedEnemy::RangedEnemy(GameHero *hero, const float &x, const float &y, const float &str, const bool &par,
                         const bool &onf, const float &h, const bool &facingR, const float &s) :
                         Enemy(hero, x, y, str, par, onf, h, facingR, s) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());
    attackRange = RANGED_ATTACK_RANGE;
    attackTimeStep = RANGED_ATT_TIMESTEP;
    setAttackBehaviour(std::make_shared<ShootingBehaviour>());
}

RangedEnemy::RangedEnemy(const RangedEnemy &copied) : Enemy(copied) {
        this->aggro = false;
        this->paralyzed = false;
}

RangedEnemy &RangedEnemy::operator=(const RangedEnemy &rangedEnemy) {
    this->hero = rangedEnemy.getHero();
    this->aggro = false;
    this->paralyzed = false;
    return *this;
}

/*
const EntityPositions RangedEnemy::move(const Direction &direction, const float &distance) {
    EntityPositions prevPosition;

    updateAggro();

    prevPosition = allPositions;

    if (!paralyzed && aggro) {

        if (abs(hero->getSprite().getPosition().x - sprite.getPosition().x) >= attackRange) { //if enemy is not paralyzed and aggro is active

            if (facingRight) { //if enemy is facing right
                prevPosition = GameCharacter::move(Direction::RIGHT, distance); //move right

            } else {
                prevPosition = GameCharacter::move(Direction::LEFT, distance); //else move left
            }

        }
    }

    return prevPosition;
}
 */
