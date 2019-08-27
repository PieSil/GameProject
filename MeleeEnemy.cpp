/**
 * Project Game
 */


#include "MeleeEnemy.h"

/**
 * MeleeEnemy implementation
 */

const SpriteParams MeleeEnemy::meleeParams(
        MELEE_PATH, MELEE_WIDTH, MELEE_HEIGHT, MELEE_SCALE, MELEE_HITBOX_X, MELEE_HITBOX_Y, MELEE_IDLE_ROW,
        MELEE_IDLE_LAST_COL, MELEE_MOV_ROW, MELEE_MOV_LAST_COL, MELEE_ATT_ROW,
        MELEE_ATT_LAST_COL, MELEE_ATT_OFFSET, MELEE_SHOOT_ROW, MELEE_SHOOT_LAST_COL, MELEE_DEATH_ROW,
        MELEE_DEATH_LAST_COL);


MeleeEnemy::MeleeEnemy(GameHero *hero, const float &x, const float &y, const float &str, const bool &par,
                       const bool &onf,
                       const float &h, const bool &facingR, const float &s) : Enemy(hero, x, y, str, par, onf, h,
                                                                                    facingR, s) {

    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());
    setupAudio();
    attackRange = MELEE_ATTACK_RANGE;
    attackTimeStep = MELEE_ATT_TIMESTEP;
    setAttackBehaviour(std::make_shared<MeleeBehaviour>());
}

MeleeEnemy::MeleeEnemy(const MeleeEnemy &copied) : Enemy(copied) {
    this->aggro = false;
    this->paralyzed = false;
}

MeleeEnemy &MeleeEnemy::operator=(const MeleeEnemy &meleeEnemy) {
        this->hero = meleeEnemy.getHero();
        this->aggro = false;
        this->paralyzed = false;
        return *this;
}

const std::pair<bool, Hitbox> MeleeEnemy::attack(const bool &bypassClock) {

    std::pair<bool, Hitbox> result;

    result.first = false;

    if (abs(hero->getSprite().getPosition().x - sprite.getPosition().x) <= attackRange)
        result = Enemy::attack(bypassClock);

    return  result;
}
