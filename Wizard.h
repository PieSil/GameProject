/**
 * Project Game
 */


#ifndef _WIZARD_H
#define _WIZARD_H

#include "GameHero.h"
#include "ShootingCharacter.h"


class Wizard: public GameHero, public ShootingCharacter {
public:
    Wizard(const float &x, const float &y, const float &str = DEF_GAMEHERO_STRENGTH, const bool &onf = false,
           const float &m = 10., const float &h = DEF_GAMEHERO_HEALTH, const bool &facingR = true,
           const float &s = HERO_SPEED);

    //default constructor
    Wizard();

    //copy constructor
    Wizard(const Wizard &copied);

    //assignment operator
    Wizard& operator =(const Wizard& wizard) = default;

    void specialBehaviour() override;

    //void updateBehaviour();

    float getMana() const {
        return mana;
    }

    void setMana(float mana) {
        Wizard::mana = mana;
    }

    const SpriteParams *getParameters() const override {
        return &wizardParams; //overrides getParameters to return a pointer to wizardParams instead of entityParams
    }

private:
    float mana;

    static const SpriteParams wizardParams;
};

#endif //_WIZARD_H