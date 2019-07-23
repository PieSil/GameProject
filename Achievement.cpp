//
// Created by Pietro on 2019-07-20.
//

#include "Achievement.h"

Achievement::Achievement(Subject *subject, const AchievementType &type) : subject(subject), type(type), unlocked(false) {
    subject->registerObserver(this);
    setup(type);
}

void Achievement::unlock() {
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

void Achievement::setup(const AchievementType& type) {

    sf::Font font;
    if(!font.loadFromFile(FONT_PATH))
        //TODO: throw exception

        switch (type) {
            case AchievementType::DistanceWalked:
                name = sf::Text("Explorer", font, 14);
                break;

            case AchievementType::EnemiesKilled:
                name = sf::Text("Killer", font, 14);
                break;

            case AchievementType::BossKilled:
                name = sf::Text("Theseus", font, 14);
                break;

            default:
                //TODO: throw exception?
                break;
        }
}

Achievement::Achievement(const Achievement &copied) : subject(copied.getSubject()), type(copied.getType()), unlocked(copied.isUnlocked()) {
    subject->registerObserver(this);
    setup(type);
}
