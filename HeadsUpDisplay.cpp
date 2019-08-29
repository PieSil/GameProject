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
        std::cout << "Could not load font file from this path: " << FONT_PATH << std::endl;
    }

    //use string stream to be able to round current health and max health values
    //to desired amount of decimal digits

    unsigned short lineNumber = 0; //number of text lines that needs to be separated
                                   //from each other (ex health, ability state, mana, ecc.) 
                                   //increment after initialization of new text attribute

    unsigned short lineOffset = 70; //height offset between separated lines of text

    std::string healthString = getNewHealth();

    healthText = sf::Text(healthString, font, 50);

    healthText.setPosition(0, lineOffset * lineNumber);

    lineNumber++;

    std::string abilityString = getAbilityState();

    abilityText = sf::Text(abilityString, font, 50);

    abilityText.setPosition(0, lineOffset * lineNumber);

    lineNumber++;

    abilityText.setFillColor(sf::Color::Cyan);

    std::string statusString = getNewStatus();

    statusText = sf::Text(statusString, font, 50);

    statusText.setPosition(0, lineOffset * lineNumber);

    statusText.setFillColor(sf::Color::Magenta);

    lineNumber++;

}

void HeadsUpDisplay::updateHUD() {
    updateHealth();

    updateAbility();

    updateStatus();
}

void HeadsUpDisplay::display() {
    window->draw(healthText);

    window->draw(abilityText);

    window->draw(statusText);
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
    healthText.setString(healthString);
    healthText.setFont(font);
}

const std::string HeadsUpDisplay::getAbilityState() {

    std::string abilityString;

    if (hasMana) {

        if (auto w = dynamic_cast<Wizard *>(hero)) {

            std::string currentMana = std::to_string(w->getMana());

            std::string maxMana = std::to_string(DEF_MANA);

            //create the text that will be displayed
            abilityString = "Mana: " + currentMana + "/" + maxMana;
        }

    } else {

        abilityString = "Ability: ";

        if (hero->isAbilityAvailable()) {
            abilityString += "Available";
            abilityText.setFillColor(sf::Color::Cyan);
        } else {
            abilityString += "Recharging";
            abilityText.setFillColor(sf::Color::Red);
        }

        return abilityString;
    }

    return abilityString;

}

void HeadsUpDisplay::updateAbility() {
        std::string abilityString = getAbilityState();
        abilityText.setString(abilityString);
        abilityText.setFont(font);
}

void HeadsUpDisplay::updateStatus() {
    std::string statusString = getNewStatus();
    statusText.setString(statusString);
    statusText.setFont(font);
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

