/**
 * Project Game
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "GameCharacter.h"

class Projectile : public MovingEntity {
public:
    Projectile(const float &x, const float &y, const bool &facingR = true, const bool &friendly = true,
               const float &movSpeed = PROJ_SPEED);
    ~Projectile() {};

    const EntityPositions move(const float &distance);

    virtual void characterCollision(GameCharacter* character) = 0;

    bool isFriendly() const {
        return friendly;
    }

    virtual void destroy();

protected:
    bool friendly;

};

#endif //_PROJECTILE_H