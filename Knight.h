/**
 * Project Game
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "GameHero.h"
#include "MeleeBehaviour.h"


class Knight: public GameHero {
public:
    Knight(const float &x, const float &y, const float &str = DEF_HERO_STRENGTH, const bool &onf = false,
           const float &h = DEF_HERO_HEALTH, const bool &facingR = true, const float &s = HERO_SPEED);
    virtual ~Knight() {};

    //default constructor
    Knight();

    //copy constructor
    Knight(const Knight &copied);

    void specialBehaviour() override;

    const bool getDamaged(const float &damage) override;

    void updateStatus() override;

    void setupAudio() override;

    const SpriteParams *getParameters() const override {
        return &knightParams; //overrides getParameters to return a pointer to knightParams instead of entityParams
    }

    bool isInvincible() const {
        return invincible;
    }

protected:

    static const SpriteParams knightParams;
    bool invincible;

};

#endif //_KNIGHT_H