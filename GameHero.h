/**
 * Project Game
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "Subject.h"
#include <list>

struct achievementCounters {

    achievementCounters() : distanceWalked(0), enemiesKilled(0), bossKilled(false) {};

    float distanceWalked;
    int enemiesKilled;
    bool bossKilled;
};

class GameHero: public GameCharacter, public Subject {
public:
    GameHero(const float &x, const float &y, const float &str = DEF_HERO_STRENGTH, const bool &onf = false,
             const float &h = DEF_HERO_HEALTH, const bool &facingR = true, const float &s = HERO_SPEED);

    //default constructor
    GameHero();

    //copy constructor
    GameHero(const GameHero &copied);

    virtual ~GameHero() = 0;

    const EntityPositions move(const Direction &direction, const float &distance) override;

    virtual const bool specialBehaviour();

    void setupAnimations(const SpriteParams *parameters) override;

    void animate() override;

    void incrDistanceWalked(const float& distance);

    void incrEnemiesKilled(const int& enemies = 1);

    void setBossKilled(const bool& isKilled = true);

    void registerObserver(Observer *obs) override;

    void removeObserver(Observer *obs) override;

    void notifyObservers() const override;

    //void updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) override;

protected:

    std::list<Observer*> observers;
    achievementCounters counters;

};

#endif //_GAMEHERO_H