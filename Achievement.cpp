//
// Created by Pietro on 2019-07-20.
//

#include "Achievement.h"

Achievement::Achievement(Subject *subject, const AchievementType &type) : subject(subject), type(type) {
    subject->registerObserver(this);
}

void Achievement::unlock() {
    unlocked = true;
    removeSubject();
}

void Achievement::update(const float &distanceWalked, const int &enemiesKilled, const bool &bossKilled) {
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

void Achievement::removeSubject() {
    if (subject != nullptr) {
        subject->removeObserver(this);
    }

    subject = nullptr;
}
