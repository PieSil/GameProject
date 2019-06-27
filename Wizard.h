/**
 * Project Game
 */


#ifndef _WIZARD_H
#define _WIZARD_H

#include "GameHero.h"


class Wizard: public GameHero {
public:
    Wizard(const float &x, const float &y, const float &str = DEF_GAMEHERO_STRENGTH, const bool &onf = false,
           const float &m = 10., const float &h = DEF_GAMEHERO_HEALTH, const bool &facingR = true,
           const float &s = HERO_SPEED);

    //default constructor
    Wizard();

    //copy constructor
    Wizard(Wizard &copied);

    //assignment operator
    Wizard& operator =(const Wizard& initializer) = default;

    void specialBehaviour() override;

    void move(const Direction& direction, const float& distance);

    //void updateBehaviour();

    float getMana() const {
        return mana;
    }

    void setMana(float mana) {
        Wizard::mana = mana;
    }

private:
    void initSprite(const float& x, const float& y);
    void giveHitbox();

    float mana;
};

#endif //_WIZARD_H