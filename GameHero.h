/**
 * Project Game
 */


#ifndef _GAMEHERO_H
#define _GAMEHERO_H

#include "GameCharacter.h"
#include "SpriteSubject.h"
#include <list>


class GameHero: public virtual GameCharacter, public SpriteSubject {
public:
    GameHero(const float &x, const float &y, const float &str = DEF_GAMEHERO_STRENGTH, const bool &onf = false,
             const float &h = DEF_GAMEHERO_HEALTH, const bool &facingR = true, const float &s = HERO_SPEED);
    virtual ~GameHero() {
    };

    //default constructor
    GameHero();

    //copy constructor
    GameHero(const GameHero &copied);

    void move(const Direction &direction, const float &distance) override;

    void centerView() {
        view->setCenter(sprite.getPosition());
    };

    //SpriteSubject methods:
    void registerObserver(SpriteObserver *observer) override {
        enemies.push_back(observer);
    }

    void removeObserver(SpriteObserver *observer) override {
        enemies.remove(observer);
    }

    void notifyObservers() override {
        for (auto enemy : enemies) {

            enemy->update(this->sprite); //update enemies giving info on hero sprite
        }
    }

    void setView(sf::View *view) {
        GameHero::view = view;
    }

    virtual void specialBehaviour() = 0;

    //void updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) override;

protected:
    std::list<SpriteObserver*> enemies;

    sf::View* view;

};

#endif //_GAMEHERO_H