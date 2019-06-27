/**
 * Project Game
 */


#include "Game.h"

/**
 * Game implementation
 */

Game::Game(Heroytype heroT, std::unique_ptr<GameWindow> w) : frameTime(1. / FRAMERATE), window(std::move(w)) {
    if (heroT == KNGT) {
        hero = std::move(
                std::unique_ptr<Knight>(new Knight(window->getWindowSize().x / 2., window->getWindowSize().y / 2.)));
    } else if (heroT == WZRD) {
        hero = std::move(
                std::unique_ptr<Wizard>(new Wizard(window->getWindowSize().x / 2., window->getWindowSize().y / 2.)));
    } else {
        //TODO: throw exception
    }
}

void Game::updateLevel() {
    handleInput();
    window->update();
}

void Game::moveHero(const Direction &direction) {

    if (auto k = dynamic_cast<Knight *>(hero.get())) {
        k->move(direction, k->getMovementSpeed() * elapsed.asSeconds()); //passes speed * elapsed time as distance
    } else if (auto w = dynamic_cast<Wizard *>(hero.get())) {
        w->move(direction, w->getMovementSpeed() * elapsed.asSeconds()); //passes speed * elapsed time as distance
    } else {
        //TODO: throw exception? Constructor should've already checked if hero value is valid
    }

}


void Game::renderLevel() {
    //clears window:
    window->beginDraw();

    //draws hitboxes on window, temporary, needed to see if hitboxes correctly match the sprites
    window->draw(hero->getHitbox());

    //draws elements on window:
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
