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

    ground = Hitbox(sf::Vector2f(window->getWindowSize().x / 2., 500), 600, 10, 1, 1, 1);
}

void Game::updateLevel() {
        handleInput();
        //updatePhysics(hero.get());
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


void Game::renderLevel() const {
    //clears window:
    window->beginDraw();

    //draws hitboxes on window, needed to see if hitboxes correctly match the sprites
    drawHitbox(&(hero->getHitbox()));
    drawHitbox(&ground);


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

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && hero->isOnGround()) {
            hero->setOnGround(false);
            hero->setVelocityY(30);
        }

        updatePhysics(hero.get());

        //game updated, subtract fixed time-step and "reset" elapsed time
        //game will update again when elapsed equals the fixed time-step chosen
        elapsed -= sf::seconds(frameTime);
    }
}

void Game::drawHitbox(const Hitbox *hitbox) const {
    window->draw(hitbox->getHitbox());
    window->draw(hitbox->getUpperEdge());
    window->draw(hitbox->getLowerEdge());
    window->draw(hitbox->getRightEdge());
    window->draw(hitbox->getLeftEdge());

}

void Game::updatePhysics(GameCharacter *character) {

    //game updates ony if elapsed time is >= than fixed time-step chosen
    if (elapsed.asSeconds() >= frameTime) {

    character->jump(character->getVelocityY());

    float gravity = -2;
    if (!character->isOnGround()) {  //If you are not on ground//Add gravity
        character->setVelocityY(character->getVelocityY() + gravity);
        checkOnGround(character);
    }
    if (character->isOnGround()) {
        character->setVelocityY(0);
    }
        //game updated, subtract fixed time-step and "reset" elapsed time
        //game will update again when elapsed equals the fixed time-step chosen
        elapsed -= sf::seconds(frameTime);
    }
}

void Game::checkOnGround(GameCharacter *character) {
    if (character->getHitbox().checkLowerEdge().intersects(ground.checkUpperEdge())) {
        character->setOnGround(true);
    } else {
        character->setOnGround(false);
    }
}