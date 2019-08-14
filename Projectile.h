/**
 * Project Game
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "GameCharacter.h"
#include "GameHero.h"
#include "Enemy.h"

class Projectile : public MovingEntity {
public:
    Projectile(const float &x, const float &y, const bool &facingR = true, const bool &friendly = true,
               const float &movSpeed = PROJ_SPEED);

    Projectile(GameHero *hero, const float &movSpeed);
    Projectile(Enemy *enemy, const float &movSpeed);

    ~Projectile() {};

    const EntityPositions move(const float &distance);

    virtual void characterCollision(GameCharacter* character) = 0;

    bool isFriendly() const {
        return friendly;
    }

protected:
    bool friendly;

};

#endif //_PROJECTILE_H