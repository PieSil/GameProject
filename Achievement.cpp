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
    //removeSubject();
}

void Achievement::update(const float &distanceWalked, const int &enemiesKilled, const bool &bossKilled) {
    if (!unlocked) {
        switch (type) {
            case AchievementType::DistanceWalked:
                if (distanceWalked >= 100) {
                    unlock();
                }
                break;

            case AchievementType::EnemiesKilled:
                if (enemiesKilled >= 2) {
                    unlock();
                }
                break;

            case AchievementType::BossKilled:
                if (bossKilled) {
                    unlock();
                }
                break;

            default:
                //TODO: throw exception?
                break;
        }
    }
}

void Achievement::removeSubject() {
    if (subject != nullptr) {
        subject->removeObserver(this);
    }

    subject = nullptr;
}

void Achievement::setup(const AchievementType &type) {

    if (!font.loadFromFile(FONT_PATH)) {
        //TODO: throw exception
    }

    description = sf::Text("Achievement Unlocked: ", font, 10);

    switch (type) {
        case AchievementType::DistanceWalked:
            if (!texture.loadFromFile(WALKER_PATH)) {
                //TODO: throw exception
            }
            name = sf::Text("Explorer", font, 10);
            description.setString(description.getString() + name.getString());
            break;

        case AchievementType::EnemiesKilled:
            if (!texture.loadFromFile(KILLER_PATH)) {
                //TODO: throw exception
            }
            name = sf::Text("Killer", font, 10);
            description.setString(description.getString() + name.getString());
            break;

        case AchievementType::BossKilled:
            if (!texture.loadFromFile(THESEUS_PATH)) {
                //TODO: throw exception
            }
            name = sf::Text("Theseus", font, 10);
            description.setString(description.getString() + name.getString());
            break;

        default:
            //TODO: throw exception?
            break;
    }

    sf::FloatRect textRect = description.getLocalBounds();
    description.setOrigin(textRect.width/2., description.getOrigin().y);
    icon.setTexture(texture);
    icon.setOrigin(icon.getOrigin().x + icon.getTextureRect().width, icon.getOrigin().y);

}

Achievement::Achievement(const Achievement &copied) : subject(copied.getSubject()), type(copied.getType()),
                                                      unlocked(copied.isUnlocked()) {
    subject->registerObserver(this);
    setup(type);
}
