//
// Created by Pietro on 2019-08-15.
//

#ifndef GAMEPROJECT_HEADSUPDISPLAY_H
#define GAMEPROJECT_HEADSUPDISPLAY_H


#include "gameValues.h"
#include "GameHero.h"
#include "Wizard.h"
#include "Knight.h"
#include "GameWindow.h"
#include <iomanip>
#include <sstream>

class HeadsUpDisplay {
public:
    HeadsUpDisplay(GameHero *hero, GameWindow* window);
    HeadsUpDisplay() = default;
    ~HeadsUpDisplay() = default;

    void updateHUD();

    void display();

    const sf::Text getHealth() const {

        sf::Text healthText = healthText;
        healthText.setFont(font);

        return healthText;

    };

    const sf::Text getMana() const {
        sf::Text manaText = abilityText;
        manaText.setFont(font);

        return manaText;
    }

private:
    void setup();

    const std::string getNewHealth();

    void updateHealth();

    const std::string getAbilityState();

    void updateAbility();

    const std::string getNewStatus();

    void updateStatus();

    bool hasMana;
    GameWindow *window;
    GameHero *hero;
    sf::Font font;
    sf::Text healthText;
    sf::Text abilityText;
    sf::Text statusText;


};


#endif //GAMEPROJECT_HEADSUPDISPLAY_H
