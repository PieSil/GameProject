/**
 * Project Game
 */


#include "BossEnemy.h"

/**
 * BossEnemy implementation
 */

const SpriteParams BossEnemy::bossParams(BOSS_WIDTH, BOSS_HEIGHT, BOSS_HITBOX_X, BOSS_HITBOX_Y, BOSS_SCALE,
                                         BOSS_PATH, BOSS_IDLE_ROW,
                                         BOSS_IDLE_LAST_COL, BOSS_MOV_ROW, BOSS_MOV_LAST_COL, BOSS_ATT_ROW,
                                         BOSS_ATT_LAST_COL, BOSS_ATT_OFFSET, BOSS_SHOOT_ROW, BOSS_SHOOT_LAST_COL);

BossEnemy::BossEnemy(GameHero *hero, const float &x, const float &y, const float &str, const bool &par, const bool &onf,
                     const float &h, const bool &facingR, const float &s) : Enemy(hero, x, y, str, par, onf, h, facingR,
                                                                                  s) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());
    attackRange = BOSS_SHOOT_RANGE;
    shootingBehaviour = std::make_shared<ShootingBehaviour>();
    meleeBehaviour = std::make_shared<MeleeBehaviour>();
    setAttackBehaviour(shootingBehaviour);

}


const std::pair<bool, Hitbox> BossEnemy::updateCombat() {

    if (abs(hero->getSprite().getPosition().x - this->sprite.getPosition().x) <= 32 && typeid(attackBehaviour.get()) != typeid(MeleeBehaviour*)) {
        setAttackBehaviour(this->meleeBehaviour);
        attackRange = BOSS_ATTACK_RANGE;
    }

    else if (typeid(attackBehaviour.get()) != typeid(ShootingBehaviour*)) {
                setAttackBehaviour(this->shootingBehaviour);
        attackRange = BOSS_SHOOT_RANGE;
    }

    return Enemy::updateCombat();
}



