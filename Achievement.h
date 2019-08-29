//
// Created by Pietro on 2019-07-20.
//

#ifndef GAMEPROJECT_ACHIEVEMENT_H
#define GAMEPROJECT_ACHIEVEMENT_H

#include "Observer.h"
#include "Subject.h"
#include "gameValues.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

enum class AchievementType {
    EnemiesKilled, DistanceWalked, BossKilled
};

class Achievement : public Observer {

public:
    Achievement(Subject *subject, const AchievementType &type);

    Achievement(const Achievement& copied);

    virtual ~Achievement() {
        removeSubject();
    };

    void update(const float &distanceWalked, const int &enemiesKilled, const bool &bossKilled) override;

    const bool calculateDescPos(const int &index, const float &windowWidth);

    const bool calculateIconPos(const int &index, const float &windowWidth);

    const bool isJustUnlocked();

    bool isUnlocked() const {
        return unlocked;
    }

    AchievementType getType() const {
        return type;
    }

    Subject *getSubject() const {
        return subject;
    }

    const sf::Sprite &getIcon() const {
        return icon;
    }

    const sf::Text &getDescription() const {
        return description;
    }

protected:
    void unlock();
    void setup(const AchievementType& type);
    void removeSubject();

    AchievementType type;
    bool unlocked;
    Subject* subject;

    sf::Texture texture;
    sf::Sprite icon;
    sf::Text description;
    sf::Font font;
    sf::Clock clock;
};


#endif //GAMEPROJECT_ACHIEVEMENT_H
