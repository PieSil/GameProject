//
// Created by Pietro on 2019-07-20.
//

#include "Achievement.h"

Achievement::Achievement(Subject *subject, const AchievementType &type) : subject(subject), type(type),
                                                                          unlocked(false) {
    subject->registerObserver(this);
    setup(type);
}

void Achievement::unlock() {
    clock.restart();
    unlocked = true;
}

void Achievement::update(const float &distanceWalked, const int &enemiesKilled, const bool &bossKilled) {
    if (!unlocked) {
        switch (type) {
            case AchievementType::DistanceWalked:
                if (distanceWalked >= 46 * TILE_SIZE.x) {
                    unlock();
                }
                break;

            case AchievementType::EnemiesKilled:
                if (enemiesKilled >= 5) {
                    unlock();
                }
                break;

            case AchievementType::BossKilled:
                if (bossKilled) {
                    unlock();
                }
                break;
        }
    }
}

void Achievement::setup(const AchievementType &type) {

    if (!font.loadFromFile(FONT_PATH)) {
        std::cout << "Could not load font file from this path: " << FONT_PATH << std::endl;
    }

    description = sf::Text("Achievement Unlocked: ", font, 50);
    std::string name;

    switch (type) {
        case AchievementType::DistanceWalked:
            if (!texture.loadFromFile(WALKER_PATH)) {
                std::cout << "Could not load texture file from this path: " << WALKER_PATH << std::endl;
            }
            name = "Explorer";
            break;

        case AchievementType::EnemiesKilled:
            if (!texture.loadFromFile(KILLER_PATH)) {
                std::cout << "Could not load texture file from this path: " << KILLER_PATH << std::endl;
            }
            name = "Killer";
            break;

        case AchievementType::BossKilled:
            if (!texture.loadFromFile(THESEUS_PATH)) {
                std::cout << "Could not load texture file from this path: " << THESEUS_PATH << std::endl;
            }
            name = "Theseus";
            break;
    }

    //create achievement description
    description.setString(description.getString() + name);

    //store bounding rectangle of text in a variable and use it to reset its origin point
    sf::FloatRect textRect = description.getLocalBounds();
    description.setOrigin(textRect.width/2., description.getOrigin().y);

    //set icon texture
    icon.setTexture(texture);
    //set x coordinate of origin to the right edge of the icon:
    icon.setOrigin(icon.getOrigin().x + icon.getTextureRect().width, icon.getOrigin().y);
    icon.setScale(8,8);

}

Achievement::Achievement(const Achievement &copied) : subject(copied.getSubject()), type(copied.getType()),
                                                      unlocked(copied.isUnlocked()) {
    subject->registerObserver(this);
    setup(type);
}

const bool Achievement::calculateDescPos(const int &index, const float &windowWidth) {

    bool descriptionUpdated = false;

    if (isJustUnlocked()) {

        float descriptionTop = 200; //set y coordinate of description upper edge

        description.setPosition(windowWidth/2., descriptionTop + (description.getCharacterSize()) * index);
        descriptionUpdated = true;
    }

    return descriptionUpdated;
}

const bool Achievement::calculateIconPos(const int &index, const float &windowWidth) {

    if (unlocked) {

        float iconTop = 0; //set y coordinate of icon upper edge
        float right = windowWidth; //set x coordinate of icon right edge

        icon.setPosition((right - (icon.getGlobalBounds().width * index)), iconTop);
    }

    return unlocked;
}

const bool Achievement::isJustUnlocked()  {

    bool justUnlocked = false;

    if (clock.getElapsedTime().asSeconds() <= NOTIFY_DURATION) {
        justUnlocked = true;
    }

    return justUnlocked;
}
