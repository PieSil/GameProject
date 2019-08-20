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
    explicit GameOver(Game *game);

    ~GameOver() override;

    void update() override;

    void draw() override;

    void handleInput() override;

private:

    SelectedOption selected;
    sf::Font font;
    sf::Text gameOverText;
    std::vector<std::pair<sf::Text, sf::RectangleShape>> options;
};


#endif //GAMEPROJECT_GAMEOVER_H
