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

    bool isUnlocked() const {
        return unlocked;
    }

    void setIconPosition(const float& x, const float& y) {
        icon.setPosition(x, y);
    }

    void setIconPosition(const sf::Vector2f& position) {
        icon.setPosition(position);
    }

    AchievementType getType() const {
        return type;
    }

    Subject *getSubject() const {
        return subject;
    }

    const sf::Text &getName() const {
        return name;
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
    sf::Text name;
    sf::Text description;

};


#endif //GAMEPROJECT_ACHIEVEMENT_H
