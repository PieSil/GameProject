//
// Created by Pietro on 2019-07-12.
//

#include "GameState.h"
#include "MovingEntity.h"
#include "GameEntity.h"
#include "Game.h"
#include "PlayingState.h"

PlayingState::PlayingState(Game *game, const Herotype &heroT) : GameState(game) {

    createLevel(heroT);
    createView();
}

void PlayingState::update() {

    sf::Time elapsed = game->getElapsed();

    if (elapsed.asSeconds() >= game->getFrameTime()) { //game updates ony if elapsed time is >= than fixed time-step chosen

        handleInput(); //polls events from keyboard

        level.updateLevel(elapsed.asSeconds());

        PlayingState::updateView();

        //game updated, subtract fixed time-step and "reset" elapsed time
        //game will update again when elapsed equals the fixed time-step chosen
        elapsed -= sf::seconds(game->getFrameTime());
        game->setElapsed(elapsed);
    }

    level.animateCharacters();

    game->getWindow()->update();
}

void PlayingState::draw() {

    //draws hitboxes on window, needed to see if hitboxes correctly match the sprites
    //drawHitbox(level.getHero()->getHitbox());

    game->getWindow()->draw(level.getGameMap());

    /*
    for (auto& projectile : level.getProjectiles()) {
        drawHitbox(projectile->getHitbox());
    }
    */

    /*
    for (auto tile : gameMap.getTiles()) {
        drawHitbox(tile.getHitbox());
    }
    */

    //draws sprites on window:
    game->getWindow()->draw(level.getHero()->getSprite());

    for (const auto &enemy : level.getEnemies()) {
        //drawHitbox(enemy->getHitbox());
        game->getWindow()->draw(enemy->getSprite());
    }

    for (const auto& projectile : level.getProjectiles()) {
        game->getWindow()->draw(projectile->getSprite());
    }
}

void PlayingState::handleInput() {
    bool keyPressed = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        PlayingState::moveHero(Direction::RIGHT, level.getHero()->getMovementSpeed() * game->getElapsed().asSeconds());
        keyPressed = true;
    }

    //move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        PlayingState::moveHero(Direction::LEFT, level.getHero()->getMovementSpeed() * game->getElapsed().asSeconds());
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

    if (!keyPressed && level.getHero()->getState() != EntityState::MELEE && level.getHero()->getState() != EntityState::SHOOTING) {
        level.getHero()->setState(EntityState::IDLE);
    }
}

void PlayingState::createLevel(const Herotype &heroT) {
    level = GameLevel(heroT);
}

void PlayingState::createView() {
    view = sf::View(
            sf::View(sf::Vector2f(level.getHero()->getSprite().getPosition()), sf::Vector2f(8 * TILE_SIZE.x, 8 * TILE_SIZE.y)));
    updateView();
}

void PlayingState::updateView() {

    auto hero = level.getHero().get();

    if (!(hero->getSprite().getPosition().x - view.getSize().x / 2. < 0 ||
          hero->getSprite().getPosition().x + view.getSize().x / 2. > MAP_COLUMNS * TILE_SIZE.x)) {
        view.setCenter(hero->getSprite().getPosition().x, view.getCenter().y);
        game->getWindow()->setView(view);
    }
}

void PlayingState::moveHero(const Direction &direction, const float &distance) {

    level.moveCharacter(level.getHero().get(), direction, distance);
    updateView();
}

void PlayingState::drawHitbox(const Hitbox &hitbox) const {
    //draw hitbox
    game->getWindow()->draw(hitbox.getHitbox());

    //draw edges
    game->getWindow()->draw(hitbox.getUpperEdge());
    game->getWindow()->draw(hitbox.getLowerEdge());
    game->getWindow()->draw(hitbox.getRightEdge());
    game->getWindow()->draw(hitbox.getLeftEdge());
}