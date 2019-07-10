/**
 * Project Game
 */


#ifndef _FIREBALL_H
#define _FIREBALL_H

#include "Projectile.h"


class Fireball: public Projectile {
public:
    Fireball(const float& x, const float&y, const bool& facingR = true, const bool& friendly = true, const float& movSpeed = PROJ_SPEED);
    ~Fireball() {};

    void characterCollision(GameCharacter *character) override;

    void destroy() override;

    const SpriteParams *getParameters() const override;

protected:
    static const SpriteParams fireballParams;
};

#endif //_FIREBALL_H