//
// Created by Pietro on 2019-07-12.
//

#include "SelectionState.h"

SelectionState::SelectionState(Game *game) : GameState(game) {

}

void SelectionState::update() {

    Herotype hero;
    
    char selection;

    do {
        std::cout << "\nPress \"k\" to select Knight, press \"w\" to select Wizard" << std::endl;

        std::cin >> selection;

        switch (selection) {
            case 'k':
                hero = Herotype::KNGT;
                break;
            case 'w' :
                hero = Herotype::WZRD;
                break;
            default:
                hero = Herotype::NOHERO;
                break;
        }
        
    } while (hero == Herotype::NOHERO);

    game->setState(State::PLAYING, hero);
}

void SelectionState::draw() {
    
}

void SelectionState::handleInput() {
}
