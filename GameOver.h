//
// Created by Pietro on 2019-07-13.
//

#ifndef GAMEPROJECT_GAMEOVER_H
#define GAMEPROJECT_GAMEOVER_H

#include "GameState.h"

enum class SelectedOption {
    CONTINUE, QUIT, NONE
};

class GameOver : public GameState {
public:
    explicit GameOver(Game *game, const bool &victory);

    ~GameOver() override;

    void update() override;

    void draw() override;

    void handleInput() override;

    void cycleColor();

private:

    SelectedOption selected;
    sf::Font font;
    sf::Text mainText;
    std::vector<std::pair<sf::Text, sf::RectangleShape>> options;
    bool victory;

    sf::Clock colorCycleClock;
};


#endif //GAMEPROJECT_GAMEOVER_H
