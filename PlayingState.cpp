//
// Created by Pietro on 2019-07-12.
//

#include "SelectionState.h"
#include "GameState.h"
#include "MovingEntity.h"
#include "GameEntity.h"
#include "Game.h"
#include "PlayingState.h"

PlayingState::PlayingState(Game *game, const Herotype &heroT) : GameState(game) {

    createLevel(heroT);
    update();
    initView();
    if(!game->getWindow()->setBackground(BACKGROUND_PATH, level.getHero()->getAllPositions().spritePosition.y)) {
        //TODO: throw exception
    }
    createAchievements();

}

void PlayingState::update() {

    sf::Time elapsed = game->getElapsed();

        handleInput(); //polls events from keyboard

        level.updateLevel(elapsed.asSeconds());

        PlayingState::updateView();

        level.animateCharacters();

        updateAchievements();

        if (level.getHero()->getState() == EntityState::DEAD)
            game->setState(State::GAMEOVER);
}

void PlayingState::draw() {

    game->getWindow()->draw(game->getWindow()->getBackground());

    //draws hitboxes on window, needed to see if hitboxes correctly match the sprites
    //drawHitbox(level.getHero()->getHitbox());

    game->getWindow()->draw(level.getGameMap());

    /*
    for (auto& projectile : level.getProjectiles()) {
        drawHitbox(projectile->getHitbox());
    }
    */

/*
    for (auto tile : level.getGameMap().getTiles()) {
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

    for (const auto& collectible : level.getCollectibles()) {
        game->getWindow()->draw(collectible->getSprite());
    }

    drawAchievements();
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

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
        level.getHero()->jump();
        keyPressed = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        level.updateCombat(level.getHero().get());
        keyPressed = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        level.updateAbility(level.getHero().get());
        keyPressed = true;
    }

    if (!keyPressed && !(level.getHero()->isAttacking()) && !(level.getHero()->isDying())) {
        level.getHero()->setState(EntityState::IDLE);
    }
}

void PlayingState::createLevel(const Herotype &heroT) {
    level = GameLevel(heroT);
}

void PlayingState::updateView() {

    auto hero = level.getHero().get();

    if (!(hero->getSprite().getPosition().x - game->getView()->getSize().x / 2. < 0 ||
          hero->getSprite().getPosition().x + game->getView()->getSize().x / 2. > MAP_COLUMNS * TILE_SIZE.x)) {
        game->getView()->setCenter(hero->getSprite().getPosition().x, game->getView()->getCenter().y);
        game->getWindow()->setView(*game->getView());
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

void PlayingState::initView() {
    game->getView()->setCenter(level.getHero()->getSprite().getPosition());
    updateView();
}

void PlayingState::createAchievements() {
    achievements.emplace_back(Achievement(level.getHero().get(), AchievementType::DistanceWalked));
    achievements.emplace_back(Achievement(level.getHero().get(), AchievementType::EnemiesKilled));
    achievements.emplace_back(Achievement(level.getHero().get(), AchievementType::BossKilled));
}

void PlayingState::updateAchievements() {

    unsigned short index = 0;
    unsigned short drawIndex = 1;

    for (auto& achievement : achievements) {
        if (achievement.isUnlocked()) {

            float top = game->getView()->getCenter().y - game->getView()->getSize().y/2.;
            float right = game->getView()->getCenter().x + game->getView()->getSize().x/2.;

            if (achievement.getElapsedTime().asSeconds() <= NOTIFY_DURATION) {
                achievement.setDescriptionPos(game->getView()->getCenter().x, top + achievement.getIcon().getTextureRect().height * drawIndex);
                drawIndex++;
            }


            achievement.setIconPosition(right - (achievement.getIcon().getTextureRect().width*index), top);

            index++;
        }
    }
}

void PlayingState::drawAchievements() {
    for (auto& achievement : achievements) {
        if (achievement.isUnlocked()) {

            if (achievement.getElapsedTime().asSeconds() <= NOTIFY_DURATION) {

                game->getWindow()->draw(achievement.getDescription());
            }

            game->getWindow()->draw(achievement.getIcon());

        }
    }
}
