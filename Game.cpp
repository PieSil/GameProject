/**
 * Project Game
 */


#include "Game.h"

/**
 * GameLevel implementation
 */

Game::Game(std::unique_ptr<GameWindow> w) : frameTime(1. / FRAMERATE), window(std::move(w)) {
    hero = std::move(std::unique_ptr<Knight>(new Knight(window->getWindowSize().x / 2., window->getWindowSize().y / 2.)));
}

void Game::updateLevel() {
    handleInput();
    window->update();
}

void Game::moveHero(const Direction &direction) {

    if (auto k = dynamic_cast<Knight *>(hero.get())) {
        k->move(direction, k->getMovementSpeed()*elapsed.asSeconds()); //passes speed * elapsed time as distance
}

}


void Game::renderLevel() {
    //clears window:
    window->beginDraw();

    //drwas elements on window:
    window->draw(hero->getSprite());

    //displays window:
    window->endDraw();
}

void Game::handleInput() {
    //game updates ony if elapsed time is >= than fixed time-step chosen
    if (elapsed.asSeconds() >= frameTime) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            moveHero(RIGHT);
        }

        //move left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            moveHero(LEFT);
        }

        //game updated, subtract fixed time-step and "reset" elapsed time
        //game will update again when elapsed equals the fixed time-step chosen
        elapsed -= sf::seconds(frameTime);
    }
}
