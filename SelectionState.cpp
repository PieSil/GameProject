//
// Created by Pietro on 2019-07-12.
//

#include "SelectionState.h"

SelectionState::SelectionState(Game *game) : GameState(game), heroT(Herotype::NOHERO) {

    std::pair<Knight*, sf::RectangleShape> knight;
    knight.first = new Knight(0,0);

    std::pair<Wizard*, sf::RectangleShape> wizard;
    wizard.first = new Wizard(0,0);

    heroes.emplace_back(knight);
    heroes.emplace_back(wizard);

    unsigned short index = 0;

    for (auto& hero : heroes) {

        hero.second = sf::RectangleShape(sf::Vector2f(50,100));
        hero.second.setFillColor(sf::Color::Transparent);
        hero.second.setOutlineColor(sf::Color::White);
        hero.second.setOutlineThickness(1);

        hero.second.setOrigin(hero.second.getSize().x/2., hero.second.getSize().y/2.);
        hero.second.setPosition(game->getView()->getCenter().x - game->getView()->getSize().x/(2*heroes.size()) + index * game->getView()->getSize().x/heroes.size() , game->getView()->getCenter().y);// + index * game->getView()->getCenter().x/heroes.size(), game->getView()->getCenter().y/2.);
        hero.first->setPosition(hero.second.getPosition());

        index++;
    }
}

void SelectionState::update() {

    for (auto &hero : heroes)
        hero.first->animate();

    handleInput();

    if (heroT != Herotype::NOHERO)
        game->setState(State::PLAYING, heroT);

    /*

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
    */
}



void SelectionState::draw() {
    for (auto& hero : heroes) {
        game->getWindow()->draw(hero.second);
        game->getWindow()->draw(hero.first->getSprite());
    }
}

void SelectionState::handleInput() {

    for (auto& hero : heroes) {

        // get the current mouse position in the window
        sf::Vector2i position = sf::Mouse::getPosition(game->getWindow()->getRenderWindow());

        // convert it to world coordinates
        sf::Vector2f mousePosition = game->getWindow()->getRenderWindow().mapPixelToCoords(position);

        if (hero.second.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            hero.first->setState(EntityState::WALKING);

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (typeid(Wizard) == typeid(*hero.first))
                    heroT = Herotype::WZRD;

                else if (typeid(Knight) == typeid(*hero.first))
                    heroT = Herotype::KNGT;
            }

        } else {
            hero.first->setState(EntityState::IDLE);
        }

    }
}
