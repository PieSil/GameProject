//
// Created by Pietro on 2019-07-12.
//

#ifndef GAMEPROJECT_PLAYINGSTATE_H
#define GAMEPROJECT_PLAYINGSTATE_H

#include <memory>
#include <iostream>
#include <list>
#include <stack>
#include "GameState.h"
#include "GameLevel.h"
#include "gameValues.h"
#include "entityPositions.h"
#include "GameWindow.h"
#include "Wizard.h"
#include "Knight.h"
#include "MeleeEnemy.h"
#include "RangedEnemy.h"
#include "BossEnemy.h"
#include "Map.h"
#include "Achievement.h"
#include "HeadsUpDisplay.h"

class PlayingState : public  GameState {

public:

    explicit PlayingState(Game *game, const Herotype &heroT = Herotype::KNGT);

    ~PlayingState () {};

    void update() override;

    void draw() override;

    void handleInput() override;

    PlayingState(const PlayingState&) = delete;
    PlayingState&operator=(const PlayingState&) = delete;

private:

    void createLevel(const Herotype& heroT);

    void updateView();

    void initView();

    void moveHero(const Direction &direction, const float &distance);

    void drawHitbox(const Hitbox &hitbox) const;

    void createAchievements();

    void updateAchievements();

    void drawAchievements();

    void setupAudio() override;

    GameLevel level;
    std::vector<Achievement> achievements;
    HeadsUpDisplay hud;

    sf::Clock victoryClock;
    bool gameWon;
};


#endif //GAMEPROJECT_PLAYINGSTATE_H
