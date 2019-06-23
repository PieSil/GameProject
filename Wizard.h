/**
 * Project Game
 */


#ifndef _WIZARD_H
#define _WIZARD_H

#include "GameHero.h"


class Wizard: public GameHero {
public:
    Wizard(int x, int y, bool onf = false, float h = defHealth, float m = 10.);

    void specialBehaviour() override;

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