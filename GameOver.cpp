//
// Created by Pietro on 2019-07-13.
//

#include "SelectionState.h"
#include "GameOver.h"

GameOver::GameOver(Game *game, const bool &victory) : GameState(game), selected(SelectedOption::NONE), victory(victory) {

    setupAudio();

    game->getWindow()->setView(*game->getHudView());

    if (!font.loadFromFile(FONT_PATH)) {
        std::cout << "Could not load font file from this path: " << FONT_PATH << std::endl;
    }

    if (!victory) {
        //initialize and set "game over" text position
        mainText = sf::Text("GAME OVER", font, CHAR_SIZE_BIG);
        mainText.setFillColor(sf::Color::Red);
    } else {
        //initialize and set "game over" text position
        mainText = sf::Text("VICTORY!", font, CHAR_SIZE_BIG);
        mainText.setFillColor(sf::Color::Yellow);
    }

    //set its origin to its center
    sf::FloatRect textRect = mainText.getLocalBounds();
    mainText.setOrigin(textRect.width / 2., textRect.height / 2.);

    mainText.setPosition(game->getHudView()->getCenter().x, (game->getHudView()->getSize().y/MAIN_COORDINATEY_DIVIDER));

    //initialize options text (ex: "retry", "quit")
    std::pair<sf::Text, sf::RectangleShape> continueOpt;

    if (!victory) {
        continueOpt.first = sf::Text("RETRY", font, CHAR_SIZE_MEDIUM);
    } else {
        continueOpt.first = sf::Text("RESTART", font, CHAR_SIZE_MEDIUM);
    }

    std::pair<sf::Text, sf::RectangleShape> quitOpt;
    quitOpt.first = sf::Text("QUIT", font, CHAR_SIZE_MEDIUM);

    //emplace the created pairs in the heroes vector
    options.emplace_back(continueOpt);
    options.emplace_back(quitOpt);

    unsigned short index = 0;

    for (auto& option : options) {

        //create the rectangles
        option.second = sf::RectangleShape(sf::Vector2f(OPTION_WIDTH, OPTION_HEIGHT));
        option.second.setFillColor(sf::Color::Transparent);
        option.second.setOutlineColor(sf::Color::White);
        option.second.setOutlineThickness(1);

        //set rectangles origin point:
        option.second.setOrigin(option.second.getSize().x / 2., option.second.getSize().y / 2.);

        //set text origin point: store bounding rectangle of text in a variable and use it to reset its origin point
        textRect = option.first.getGlobalBounds();
        option.first.setOrigin(textRect.width / 2., textRect.height/2. + OPT_ORIGINY_OFFSET);

        //set rectangles position
        option.second.setPosition(
                game->getHudView()->getCenter().x / 2. + (index * game->getHudView()->getSize().x / 2.),
                (game->getHudView()->getSize().y * OPT_Y_MULTIPLIER));

        //set the options' position to match rectangles' position
        option.first.setPosition(option.second.getPosition());

        //increase index
        index++;
    }

    audioPlayer.play(MusicID::ENDING);

}

GameOver::~GameOver() {

}

void GameOver::update() {

    cycleColor();

    switch (selected) {
        case SelectedOption::CONTINUE:
            sf::sleep(sf::seconds(SWITCH_STATE_DELAY));
            audioPlayer.stopAllMusic();
            game->setState(State::SELECTION);
            break;

        case SelectedOption::QUIT:
            audioPlayer.stopAllMusic();
            game->getWindow()->setClosed(true);
            break;

        default:
            handleInput();
    }
}

void GameOver::draw() {
    game->getWindow()->draw(mainText);

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
                if (option.first.getString() == "RETRY" || option.first.getString() == "RESTART")
                    selected = SelectedOption::CONTINUE;

                else if (option.first.getString() == "QUIT")
                    selected = SelectedOption::QUIT;
            }

        }

    }
}

void GameOver::cycleColor() {

    if (colorCycleClock.getElapsedTime().asSeconds() >= COLOR_CYCLE_TIME) {

        colorCycleClock.restart();

        if (victory) {
            if (mainText.getFillColor() == sf::Color::Yellow) {
                mainText.setFillColor(sf::Color::Magenta);
            } else if (mainText.getFillColor() == sf::Color::Magenta) {
                mainText.setFillColor(sf::Color::Green);
            } else if (mainText.getFillColor() == sf::Color::Green) {
                mainText.setFillColor(sf::Color::Yellow);
            }
        } else {
            if (mainText.getFillColor() == sf::Color::Red) {
                mainText.setFillColor(sf::Color::Magenta);
            } else if (mainText.getFillColor() == sf::Color::Magenta) {
                mainText.setFillColor(sf::Color::Blue);
            } else if (mainText.getFillColor() == sf::Color::Blue) {
                mainText.setFillColor(sf::Color::Red);
            }
        }
    }
}

void GameOver::setupAudio() {

    if (victory) {
        audioPlayer.insertMusic(MusicID::ENDING, VICTORY_MUSIC_PATH, true, STANDARD_PITCH, VICTORY_MUSIC_VOLUME);
    } else {
        audioPlayer.insertMusic(MusicID::ENDING, GAMEOVER_MUSIC_PATH, false, STANDARD_PITCH, LOW_MUSIC_VOLUME);
    }
}

