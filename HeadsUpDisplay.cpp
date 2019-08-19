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

    unsigned short lineNumber = 0; //number of text lines that needs to be separated
    //from each other (ex health, mana, ecc.) increment after initialization of new text attribute

    unsigned short lineOffset = 70; //height offset between separated lines of text

    std::string healthString = getNewHealth();

    health = sf::Text(healthString, font, 50);

    health.setPosition(0,lineOffset * lineNumber);

    lineNumber++;

    if (hasMana) {
        std::string manaString = getNewMana();

        mana = sf::Text(manaString, font, 50);

        mana.setPosition(0,lineOffset * lineNumber);

        lineNumber++;

        mana.setFillColor(sf::Color::Blue);
    }

    std::string statusString = getNewStatus();

    status = sf::Text(statusString, font, 50);

    status.setPosition(0,lineOffset * lineNumber);

    status.setFillColor(sf::Color::Magenta);

    lineNumber++;

}

void HeadsUpDisplay::updateHUD() {
    updateHealth();

    if (hasMana) {
        updateMana();
    }

    updateStatus();
}

void HeadsUpDisplay::display() {
    window->draw(health);

    if (hasMana) {
        window->draw(mana);
    }

    window->draw(status);
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
    std::string healthString = getNewHealth();
    health.setString(healthString);
    health.setFont(font);
}

const std::string HeadsUpDisplay::getNewMana() {

    std::string manaString;

    if (auto w = dynamic_cast<Wizard*>(hero) ) {

        std::string currentMana = std::to_string(w->getMana());

        std::string maxMana = std::to_string(DEF_MANA);

        //create the text that will be displayed
        manaString = "Mana: " + currentMana + "/" + maxMana;
    }

    return manaString;

}

void HeadsUpDisplay::updateMana() {
    std::string manaString = getNewMana();
    mana.setString(manaString);
    mana.setFont(font);
}

void HeadsUpDisplay::updateStatus() {
    std::string statusString = getNewStatus();
    status.setString(statusString);
    status.setFont(font);
}

const std::string HeadsUpDisplay::getNewStatus() {

    std::string statusString;
    std::list<std::string> statusList;
    bool hasStatus = false;

    if (hero->isOnFire()) {
        hasStatus = true;
        statusList.emplace_back("BRN ");
    }

    if (auto k = dynamic_cast<Knight*>(hero) ) {
        if (k->isInvincible()) {
            hasStatus = true;
            statusList.emplace_back("INV ");
        }
    }

    if (hasStatus) {

        for (const auto status : statusList) {
            statusString += status;
        }

        statusString = "Status: " + statusString;

    } else {
        statusString = "";
    }

    return statusString;
}


