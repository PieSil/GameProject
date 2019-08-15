//
// Created by Pietro on 2019-08-15.
//

#include "HeadsUpDisplay.h"


HeadsUpDisplay::HeadsUpDisplay(GameHero *hero, GameWindow *window) : hero(hero), window(window) {
    setup();
}

void HeadsUpDisplay::setup() {
    if (!font.loadFromFile(FONT_PATH)) {
        //TODO: throw exception?
    }

    //use string stream to be able to round current health and max health values
    //to desired amount of decimal digits

    std::stringstream currentHealthStream;
    currentHealthStream << std::fixed << std::setprecision(3) << hero->getHealth();
    std::string roundedCurrentHealth = currentHealthStream.str();

    std::stringstream maxHealthStream;
    maxHealthStream << std::fixed << std::setprecision(3) << DEF_HERO_HEALTH;
    std::string roundedMaxHealth = maxHealthStream.str();

    //create the text that will be displayed
    std::string healthText = "Health: " + roundedCurrentHealth + "/" + roundedMaxHealth;

    health = sf::Text(healthText, font, 50);

    health.setPosition(0,0);

}

void HeadsUpDisplay::updateHealth() {
    std::stringstream currentHealthStream;
    currentHealthStream << std::fixed << std::setprecision(3) << hero->getHealth();
    std::string roundedCurrentHealth = currentHealthStream.str();

    std::stringstream maxHealthStream;
    maxHealthStream << std::fixed << std::setprecision(3) << DEF_HERO_HEALTH;
    std::string roundedMaxHealth = maxHealthStream.str();

    //create the text that will be displayed
    std::string healthText = "Health: " + roundedCurrentHealth + "/" + roundedMaxHealth;

    health = sf::Text(healthText, font, 50);
}

void HeadsUpDisplay::updateHUD() {
    updateHealth();
}
