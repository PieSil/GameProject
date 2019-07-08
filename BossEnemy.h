/**
 * Project Game
 */


#ifndef _BOSSENEMY_H
#define _BOSSENEMY_H

#include "GameCharacter.h"
#include "Enemy.h"
#include "MeleeBehaviour.h"
#include "ShootingBehaviour.h"


class BossEnemy: public Enemy {
public:
    BossEnemy(GameHero *hero, const float &x, const float &y, const float &str = DEF_ENEMY_STRENGTH,
              const bool &par = false, const bool &onf = false, const float &h = DEF_ENEMY_HEALTH,
              const bool &facingR = true, const float &s = BOSS_SPEED);
    ~BossEnemy() {};

    const SpriteParams *getParameters() const override {
        return &bossParams;
    }

    const entityPositions updateBehaviour(const float &distance) override;

protected:
    static const SpriteParams bossParams;
    std::shared_ptr<ShootingBehaviour> shootingBehaviour;
    std::shared_ptr<MeleeBehaviour> meleeBehaviour;
};

#endif //_BOSSENEMY_H