/**
 * Project Game
 */


#ifndef _WIZARD_H
#define _WIZARD_H

#include "GameHero.h"
#include "ShootingBehaviour.h"
#include "Projectile.h"
#include "Paralyzing.h"

class Wizard: public GameHero {
public:
    Wizard(const float &x, const float &y, const float &str = DEF_HERO_STRENGTH, const bool &onf = false,
           const int &m = DEF_MANA, const float &h = DEF_HERO_HEALTH, const bool &facingR = true,
           const float &s = HERO_SPEED);

    //default constructor
    Wizard();

    //copy constructor
    Wizard(const Wizard &copied);

    //assignment operator
    Wizard& operator =(const Wizard& wizard) = default;

    const std::pair<bool, Hitbox> attack(const bool &bypassClock) override;

    const bool hasEnoughMana(const int &cost);

    void updateStatus() override;

    void regenerateMana();

    void decreaseMana(const unsigned short& amount);

    void specialBehaviour() override {};

    void specialBehaviour(std::vector<std::unique_ptr<Projectile>>& levelProjectiles);

    void setupAudio() override;

    //void updateBehaviour();

    int getMana() const {
        return mana;
    }

    void setMana(int mana) {
        Wizard::mana = mana;
    }

    const SpriteParams *getParameters() const override {
        return &wizardParams; //overrides getParameters to return a pointer to wizardParams instead of entityParams
    }

private:
    int mana;

    static const SpriteParams wizardParams;
};

#endif //_WIZARD_H