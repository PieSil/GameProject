/**
 * Project Game
 */


#ifndef _PARALYZING_H
#define _PARALYZING_H

#include "Projectile.h"


class Paralyzing: public Projectile {
public:
    Paralyzing(const float& x, const float&y, const bool& facingR = true, const bool& friendly = true, const float& movSpeed = PROJ_SPEED);
    ~Paralyzing() {};

    Paralyzing(GameHero *hero, const float &movSpeed = PROJ_SPEED);

    void characterCollision(GameCharacter *character) override;

    const SpriteParams *getParameters() const override {
        return &paralyzingParams;
    }

protected:
    static const SpriteParams paralyzingParams;
};

#endif //_PARALYZING_H