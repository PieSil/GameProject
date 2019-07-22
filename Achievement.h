//
// Created by Pietro on 2019-07-20.
//

#ifndef GAMEPROJECT_ACHIEVEMENT_H
#define GAMEPROJECT_ACHIEVEMENT_H

#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

enum class AchievementType {
    EnemiesKilled, DistanceWalked, BossKilled
};

class Achievement : public Observer {

public:
    Achievement(Subject *subject, const AchievementType &type);
    virtual ~Achievement() {
        removeSubject();
    };

    void update(const float &distanceWalked, const int &enemiesKilled, const bool &bossKilled) override;

    void removeSubject();

protected:
    void unlock();

    AchievementType type;
    bool unlocked;
    Subject* subject;

    sf::Texture texture;
    sf::Sprite icon;
    sf::Text name;
    sf::Text description;
};


#endif //GAMEPROJECT_ACHIEVEMENT_H
