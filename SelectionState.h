//
// Created by Pietro on 2019-07-12.
//

#ifndef GAMEPROJECT_SELECTIONSTATE_H
#define GAMEPROJECT_SELECTIONSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

enum class TextType {
    TITLE, ACTION,
};

class SelectionState : public GameState {

public:
    explicit SelectionState(Game *game);

    ~SelectionState() {
        for (auto& hero : heroes) {
            delete(hero.first);
        }
    };

    void update() override;

    void draw() override;

    void handleInput() override;

    SelectionState(const SelectionState&) = delete;
    SelectionState&operator=(const SelectionState&) = delete;
protected:
    sf::Font font;
    Herotype heroT;
    std::vector<std::pair<GameHero*, sf::RectangleShape>> heroes;
    std::map<TextType, sf::Text> textLines;
};


#endif //GAMEPROJECT_SELECTIONSTATE_H
