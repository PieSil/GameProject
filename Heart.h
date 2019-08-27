/**
 * Project Game
 */


#ifndef _HEART_H
#define _HEART_H

#include "Collectible.h"
#include "GameHero.h"
#include "gameValues.h"
#include "SpriteParameters.h"

class Heart: public Collectible {
public:
    Heart(GameHero *hero, const float &x, const float &y, const float &heal = DEF_HERO_HEALTH);

    ~Heart() override;

    const bool updateBehaviour() override;

    void characterCollision(GameCharacter *character) override;

    void setupAudio() override;

    const SpriteParams *getParameters() const override {
        return &heartParams;
    }

protected:
    GameHero* hero;
    float heal = DEF_HERO_HEALTH;
    static const SpriteParams heartParams;
};

#endif //_HEART_H