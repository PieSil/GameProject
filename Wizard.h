/**
 * Project Game
 */


#ifndef _WIZARD_H
#define _WIZARD_H

#include "GameHero.h"


class Wizard: public GameHero {
public:
    Wizard(float x, float y, float str = DEF_GAMEHERO_STRENGTH, bool onf = false, float m = 10., float h = DEF_GAMEHERO_HEALTH, bool facingR = true, float s = HERO_SPEED);

    //default constructor
    Wizard();

    //copy constructor
    Wizard(const Wizard& copied);

    //assignment operator
    Wizard& operator =(const Wizard& initializer) = default;

    void specialBehaviour() override;

    void updateBehaviour();

    void initSprite(float x, float y) override;

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