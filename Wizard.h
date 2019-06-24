/**
 * Project Game
 */


#ifndef _WIZARD_H
#define _WIZARD_H

#include "GameHero.h"


class Wizard: public GameHero {
public:
    Wizard(float x, float y, bool onf = false, float m = 10., float h = defHealth, bool facingR = true, float s = HERO_SPEED);

    void specialBehaviour() override;

    void updateMovement();

    float getMana() const {
        return mana;
    }

    void setMana(float mana) {
        Wizard::mana = mana;
    }

protected: 
    float mana;
};

#endif //_WIZARD_H