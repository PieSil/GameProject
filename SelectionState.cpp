//
// Created by Pietro on 2019-07-12.
//

#include "SelectionState.h"

SelectionState::SelectionState(Game *game) : GameState(game), heroT(Herotype::NOHERO) {

    if (!font.loadFromFile(FONT_PATH)) {
        //TODO: throw exception?
    }

    textLines.emplace(TextType::TITLE, sf::Text("ORDEAL", font, 100));
    textLines.emplace(TextType::ACTION, sf::Text("SELECT YOUR HERO", font, 50));

    sf::Text &title = textLines.find(TextType::TITLE)->second;
    sf::Text &action = textLines.find(TextType::ACTION)->second;

    //set origin to center for every line of text except for description
    for (auto &itr : textLines) {
        sf::Text &text = itr.second;
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.width / 2., textRect.height / 2.);
    }

    //setup title

    title.setFillColor(sf::Color::Yellow);

    title.setPosition(game->getHudView()->getCenter().x, (game->getHudView()->getSize().y / 8.));

    //setup action
    action.setPosition(title.getPosition().x, title.getPosition().y + title.getGlobalBounds().height + 20);

    //create a wizard and a knight to display their sprites, create them into a pair to associate them with a RectangleShape
    std::pair<Knight *, sf::RectangleShape> knight;
    knight.first = new Knight(0, 0);

    std::pair<Wizard *, sf::RectangleShape> wizard;
    wizard.first = new Wizard(0, 0);

    //emplace the created pairs in the heroes vector
    heroes.emplace_back(knight);
    heroes.emplace_back(wizard);

    unsigned short index = 0;

    for (auto &hero : heroes) {

        //create the rectangles
        hero.second = sf::RectangleShape(sf::Vector2f(100. / heroes.size(), 200. / heroes.size()));
        hero.second.setFillColor(sf::Color::Transparent);
        hero.second.setOutlineColor(sf::Color::White);
        hero.second.setOutlineThickness(1);

        //set rectangles position:
        hero.second.setOrigin(hero.second.getSize().x / 2., hero.second.getSize().y / 2.);

        //set their position so that the rectangles are placed nicely in the window no matter the number of heroes
        //position on X axis = view center - (view size)/4 + (index of current hero) * (view size)/(2*(number of heroes-1))
        //position on Y axis = view center
        hero.second.setPosition(game->getPlayerView()->getCenter().x - game->getPlayerView()->getSize().x / 4 +
                                index * (game->getPlayerView()->getSize().x / (2 * (heroes.size() - 1))),
                                game->getPlayerView()->getCenter().y);

        //set the heroes' position to match rectangles' position
        hero.first->setPosition(hero.second.getPosition());

        //increase index
        index++;
    }
}

void SelectionState::update() {

    for (auto &hero : heroes)
        hero.first->animate();

    handleInput();

    if (heroT != Herotype::NOHERO) //if hero has been selected set state to playing with current hero
        game->setState(State::PLAYING, heroT);

}


void SelectionState::draw() {

    game->getWindow()->setView(*game->getPlayerView());

    for (auto &hero : heroes) {
        game->getWindow()->draw(hero.second);
        game->getWindow()->draw(hero.first->getSprite());
    }

    game->getWindow()->setView(*game->getHudView());

    for (auto &itr : textLines) {
        auto text = itr.second;
        game->getWindow()->draw(text);
    }
}

void SelectionState::handleInput() {

    game->getWindow()->setView(*game->getPlayerView());

    for (auto &hero : heroes) {

        // get the current mouse position in the window
        sf::Vector2i position = sf::Mouse::getPosition(game->getWindow()->getRenderWindow());

        // convert it to world coordinates
        sf::Vector2f mousePosition = game->getWindow()->getRenderWindow().mapPixelToCoords(position);

        if (mousePosition.x < hero.first->getSprite().getPosition().x) {
            hero.first->move(Direction::LEFT, 0);
        } else {
            hero.first->move(Direction::RIGHT, 0);
        }

        if (hero.second.getGlobalBounds().contains(mousePosition.x,
                                                   mousePosition.y)) { //if mouse is contained in rectangle
            hero.first->setState(EntityState::WALKING);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //and left mouse is clicked


                //check type of the hero associated with rectangle and modify the heroType attribute accordingly
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
