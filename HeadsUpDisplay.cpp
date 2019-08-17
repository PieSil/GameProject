//
// Created by Pietro on 2019-08-15.
//

#include "HeadsUpDisplay.h"


HeadsUpDisplay::HeadsUpDisplay(GameHero *hero, GameWindow *window) : hero(hero), window(window) {
    if (typeid(*hero) == typeid(Wizard))
        hasMana = true;
    else
        hasMana = false;


    setup();
}

void HeadsUpDisplay::setup() {
    if (!font.loadFromFile(FONT_PATH)) {
        //TODO: throw exception?
    }

    //use string stream to be able to round current health and max health values
    //to desired amount of decimal digits

    std::string healthText = getNewHealth();

    health = sf::Text(healthText, font, 50);

    health.setPosition(0,0);

    if (hasMana) {
        std::string manaText = getNewMana();

        mana = sf::Text(manaText, font, 50);

        mana.setPosition(0,70);

        mana.setFillColor(sf::Color::Blue);
    }

}

void HeadsUpDisplay::updateHUD() {
    updateHealth();

    if (hasMana) {
        updateMana();
    }
}

void HeadsUpDisplay::display() {
    window->draw(health);

    if (hasMana) {
        window->draw(mana);
    }
}

const std::string HeadsUpDisplay::getNewHealth() {
    std::stringstream currentHealthStream;
    currentHealthStream << std::fixed << std::setprecision(3) << hero->getHealth();
    std::string roundedCurrentHealth = currentHealthStream.str();

    std::stringstream maxHealthStream;
    maxHealthStream << std::fixed << std::setprecision(3) << DEF_HERO_HEALTH;
    std::string roundedMaxHealth = maxHealthStream.str();

    //create the text that will be displayed
    std::string healthText = "Health: " + roundedCurrentHealth + "/" + roundedMaxHealth;

    return healthText;
}


void HeadsUpDisplay::updateHealth() {
    std::string healthText = getNewHealth();
    health.setString(healthText);
    health.setFont(font);
}

const std::string HeadsUpDisplay::getNewMana() {

    std::string manaText;

    if (auto w = dynamic_cast<Wizard*>(hero) ) {

        std::string currentMana = std::to_string(w->getMana());

        std::string maxMana = std::to_string(DEF_MANA);

        //create the text that will be displayed
        manaText = "Mana: " + currentMana + "/" + maxMana;
    }

    return manaText;

}

void HeadsUpDisplay::updateMana() {
    std::string manaText = getNewMana();
    mana.setString(manaText);
    mana.setFont(font);
}


