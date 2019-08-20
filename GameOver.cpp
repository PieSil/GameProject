//
// Created by Pietro on 2019-07-13.
//

#include "SelectionState.h"
#include "GameOver.h"

GameOver::GameOver(Game *game) : GameState(game), selected(SelectedOption::NONE) {
    game->getWindow()->setView(*game->getHudView());

    if (!font.loadFromFile(FONT_PATH)) {
        //TODO: throw exception?
    }

    //initialize and set "game over" text position
    gameOverText = sf::Text("GAME OVER", font, 100);
    gameOverText.setFillColor(sf::Color::Red);

    //set its origin to its center
    sf::FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textRect.width / 2., textRect.height / 2.);

    gameOverText.setPosition(game->getHudView()->getCenter().x, (game->getHudView()->getSize().y/3.));

    //initialize options text (ex: "continue", "quit")
    std::pair<sf::Text, sf::RectangleShape> continueOpt;
    continueOpt.first = sf::Text("CONTINUE", font, 50);

    std::pair<sf::Text, sf::RectangleShape> quitOpt;
    quitOpt.first = sf::Text("QUIT", font, 50);

    //emplace the created pairs in the heroes vector
    options.emplace_back(continueOpt);
    options.emplace_back(quitOpt);

    unsigned short index = 0;

    for (auto& option : options) {

        //create the rectangles
        option.second = sf::RectangleShape(sf::Vector2f(450., 70.));
        option.second.setFillColor(sf::Color::Transparent);
        option.second.setOutlineColor(sf::Color::White);
        option.second.setOutlineThickness(1);

        //set rectangles origin point:
        option.second.setOrigin(option.second.getSize().x / 2., option.second.getSize().y / 2.);

        //set text origin point: store bounding rectangle of text in a variable and use it to reset its origin point
        textRect = option.first.getGlobalBounds();
        option.first.setOrigin(textRect.width / 2., textRect.height/2. + 10);

        //set rectangles position
        option.second.setPosition(
                game->getHudView()->getCenter().x / 2. + (index * game->getHudView()->getSize().x / 2.),
                (game->getHudView()->getSize().y * (9./14.)));

        //set the options' position to match rectangles' position
        option.first.setPosition(option.second.getPosition());

        //increase index
        index++;
    }

}

GameOver::~GameOver() {

}

void GameOver::update() {

    switch (selected) {
        case SelectedOption::CONTINUE:
            sf::sleep(sf::seconds(0.5));
            game->setState(State::SELECTION);
            break;

        case SelectedOption::QUIT:
            game->getWindow()->setClosed(true);
            break;

        default:
            handleInput();
    }
}

void GameOver::draw() {
    game->getWindow()->draw(gameOverText);

    for (const auto& option : options) {
        game->getWindow()->draw(option.first);
        game->getWindow()->draw(option.second);
    }
}

void GameOver::handleInput() {
    for (auto& option : options) {

        // get the current mouse position in the window
        sf::Vector2i position = sf::Mouse::getPosition(game->getWindow()->getRenderWindow());

        // convert it to world coordinates
        sf::Vector2f mousePosition = game->getWindow()->getRenderWindow().mapPixelToCoords(position);

        if (option.second.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) { //if mouse is contained in rectangle

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //and left mouse is clicked

                //check option associated with rectangle and set selected attribute accordingly
                if (option.first.getString() == "CONTINUE")
                    selected = SelectedOption::CONTINUE;

                else if (option.first.getString() == "QUIT")
                    selected = SelectedOption::QUIT;
            }

        }

    }
}
