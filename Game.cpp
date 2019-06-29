/**
 * Project Game
 */


#include "Game.h"
#include "GameEntity.h"
#include "MovingEntity.h"

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

    enemies.push_back(std::unique_ptr<MeleeEnemy>(
            new MeleeEnemy(window->getWindowSize().x / 2., window->getWindowSize().y / 2.)));

    ground = Hitbox(sf::Vector2f(window->getWindowSize().x / 2., 500), 600, 50, 1, 1, 1);
}

void Game::updateGame() {

    if (elapsed.asSeconds() >= frameTime) { //game updates ony if elapsed time is >= than fixed time-step chosen

        handleInput(); //polls events from keyboard

        //updates physics
        updatePhysics(hero.get());
        for (const auto &enemy : enemies) {
            updatePhysics(enemy.get());
            if (enemy->isOnGround()) {
                enemy->setVelocityY(JUMP_VELOCITY);
            }
        }

        //game updated, subtract fixed time-step and "reset" elapsed time
        //game will update again when elapsed equals the fixed time-step chosen
        elapsed -= sf::seconds(frameTime);
    }

    checkOnGround(hero.get());


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
    drawHitbox(hero->getHitbox());
    drawHitbox(ground);

    //draws sprites on window:
    window->draw(hero->getSprite());

    //draws enemies and their sprites
    for (const auto &enemy : enemies) {
        drawHitbox(enemy->getHitbox());
        window->draw(enemy->getSprite());
    }


    //displays window:
    window->endDraw();
}

void Game::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveHero(RIGHT);
    }

    //move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveHero(LEFT);
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
        hero->isOnGround()) {
        hero->setOnGround(false);
        hero->setVelocityY(JUMP_VELOCITY);
    }

}

void Game::drawHitbox(const Hitbox &hitbox) const {
    window->draw(hitbox.getHitbox());

    /*
    window->draw(hitbox.getUpperEdge());
    window->draw(hitbox.getLowerEdge());
    window->draw(hitbox.getRightEdge());
    window->draw(hitbox.getLeftEdge());
     */
}

void Game::updatePhysics(GameCharacter *character) {

    //moves character on Y axis based on its velocity
    character->moveOnY(character->getVelocityY(), UP);

//checks if the character is on ground or not
    checkOnGround(character);

    if (!character->isOnGround()) {  //if character not on ground add gravity
        character->setVelocityY(character->getVelocityY() + GRAVITY);
    }

    if (character->isOnGround()) {
        character->setVelocityY(0);
    }

}

void Game::checkOnGround(GameCharacter *character) {
    if (character->getHitbox().checkLowerEdge().intersects(ground.checkUpperEdge())) { //check if character's lowerEdge is touching ground's upper edg)) {
        character->setOnGround(true);
    } else {
        character->setOnGround(false);
    }
}