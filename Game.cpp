/**
 * Project Game
 */


#include "Game.h"
#include "GameEntity.h"
#include "MovingEntity.h"

/**
 * Game implementation
 */

Game::Game(Herotype heroT, std::unique_ptr<GameWindow> w) : frameTime(1. / FRAMERATE), window(std::move(w)) {

    createLevel(heroT);
    createView();

}

void Game::updateGame() {

    if (elapsed.asSeconds() >= frameTime) { //game updates ony if elapsed time is >= than fixed time-step chosen

        handleInput(); //polls events from keyboard

        level.updateLevel(elapsed.asSeconds());

        updateView();

        //game updated, subtract fixed time-step and "reset" elapsed time
        //game will update again when elapsed equals the fixed time-step chosen
        elapsed -= sf::seconds(frameTime);
    }

    level.animateCharacters();


    window->update();

}

void Game::moveHero(const Direction &direction) {

    level.moveCharacter(level.getHero().get(), direction, level.getHero()->getMovementSpeed() * elapsed.asSeconds());
    updateView();
}


void Game::renderLevel() const {
    //clears window:
    window->beginDraw();

    //draws hitboxes on window, needed to see if hitboxes correctly match the sprites
    //drawHitbox(level.getHero()->getHitbox());

    window->draw(level.getGameMap());

    /*
    for (auto tile : gameMap.getTiles()) {
        drawHitbox(tile.getHitbox());
    }
    */

    //draws sprites on window:
    window->draw(level.getHero()->getSprite());

    for (const auto &enemy : level.getEnemies()) {
        //drawHitbox(enemy->getHitbox());
        window->draw(enemy->getSprite());
    }

    for (const auto& projectile : level.getProjectiles()) {
        window->draw(projectile->getSprite());
    }




    //displays window:
    window->endDraw();
}

void Game::handleInput() {

    bool keyPressed = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveHero(RIGHT);
        keyPressed = true;
    }

    //move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveHero(LEFT);
        keyPressed = true;
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
        level.getHero()->isOnGround()) {
        level.getHero()->setOnGround(false);
        level.getHero()->setVelocityY(JUMP_VELOCITY);
        keyPressed = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        level.updateCombat(level.getHero().get());
        keyPressed = true;
    }

    if (!keyPressed && level.getHero()->getState() != ATTACKING && level.getHero()->getState() != SHOOTING) {
        level.getHero()->setState(IDLE);
    }
}

void Game::drawHitbox(const Hitbox &hitbox) const {
    //draw hitbox
    window->draw(hitbox.getHitbox());

    //draw edges
    window->draw(hitbox.getUpperEdge());
    window->draw(hitbox.getLowerEdge());
    window->draw(hitbox.getRightEdge());
    window->draw(hitbox.getLeftEdge());
}

void Game::createView() {
    view = std::make_shared<sf::View>(
            sf::View(sf::Vector2f(level.getHero()->getSprite().getPosition()), sf::Vector2f(8 * TILE_SIZE.x, 8 * TILE_SIZE.y)));
    updateView();
}

void Game::updateView() {

    auto hero = level.getHero().get();

    if (!(hero->getSprite().getPosition().x - view->getSize().x / 2. < 0 ||
          hero->getSprite().getPosition().x + view->getSize().x / 2. > MAP_COLUMNS * TILE_SIZE.x)) {
        view->setCenter(hero->getSprite().getPosition().x, view->getCenter().y);
        window->setView(*view);
    }
}

void Game::createLevel(Herotype heroT) {
    level = GameLevel(heroT);
}
