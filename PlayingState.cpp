//
// Created by Pietro on 2019-07-12.
//

#include "SelectionState.h"
#include "GameState.h"
#include "MovingEntity.h"
#include "GameEntity.h"
#include "Game.h"
#include "PlayingState.h"

PlayingState::PlayingState(Game *game, const Herotype &heroT) : GameState(game), gameWon(false) {

    setupAudio();

    createLevel(heroT);
    hud = HeadsUpDisplay(level.getHero().get(), game->getWindow().get());
    update();
    initView();
    if(!game->getWindow()->setBackground(BACKGROUND_PATH, level.getHero()->getAllPositions().spritePosition.y)) {
        std::cout << "Could not load background from this path: " << BACKGROUND_PATH <<std::endl;
    }
    createAchievements();

    audioPlayer.play(MusicID::LEVEL);

}

void PlayingState::update() {

    sf::Time elapsed = game->getElapsed();

        handleInput(); //polls events from keyboard

        level.updateLevel(elapsed.asSeconds());

        PlayingState::updateView();

        level.animateCharacters();

        updateAchievements();

        hud.updateHUD();

        if (level.getHero()->getState() == EntityState::DEAD && !gameWon) {
            sf::sleep(sf::seconds(SWITCH_STATE_DELAY));
            audioPlayer.stopAllMusic();
            game->setState(State::GAMEOVER);

        } else if (!gameWon && level.getHero()->isBossKilled()) {
            gameWon = true;
            victoryClock.restart();

            //kill all remaining enemies
            for (auto& enemy : level.getEnemies()) {

                if (!enemy->isDying()) {
                    enemy->setState(EntityState::DYING);
                }
            }

        } else if (gameWon && victoryClock.getElapsedTime().asSeconds() >= VICTORY_DELAY) {
            audioPlayer.stopAllMusic();
            game->setState(State::VICTORY);
        }
}

void PlayingState::draw() {

    //set view to player view
    game->getWindow()->setView(*game->getPlayerView());

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

    game->getWindow()->setView(*game->getHudView());

    drawAchievements();

    hud.display();
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

    if (!(hero->getSprite().getPosition().x - game->getPlayerView()->getSize().x / 2. < 0 ||
          hero->getSprite().getPosition().x + game->getPlayerView()->getSize().x / 2. > MAP_COLUMNS * TILE_SIZE.x)) {
        game->getPlayerView()->setCenter(hero->getSprite().getPosition().x, game->getPlayerView()->getCenter().y);
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
    game->getPlayerView()->setCenter(level.getHero()->getSprite().getPosition());
    updateView();
}

void PlayingState::createAchievements() {
    achievements.emplace_back(Achievement(level.getHero().get(), AchievementType::DistanceWalked));
    achievements.emplace_back(Achievement(level.getHero().get(), AchievementType::EnemiesKilled));
    achievements.emplace_back(Achievement(level.getHero().get(), AchievementType::BossKilled));
}

void PlayingState::updateAchievements() {

    unsigned short index = 0; //counts number of unlocked achievements
    unsigned short descIndex = 0; // counts number of descriptions to draw on screen
    const float windowWidth = game->getWindow()->getWindowSize().x;

    for (auto& achievement : achievements) {

        if (achievement.calculateIconPos(index, windowWidth)) {
            //calculateIconPos returns true if achievement is unlocked, false otherwise

            index++;
        }

        if (achievement.calculateDescPos(descIndex, windowWidth)) {
            //calculateDescPos returns true if achievement has just been
            //unlocked (and thus description needs to be drawn on screen), false otherwise

            descIndex++;
        }

    }
}

void PlayingState::drawAchievements() {
    for (auto& achievement : achievements) {

        if (achievement.isUnlocked()) {

            if (achievement.isJustUnlocked()) {

                game->getWindow()->draw(achievement.getDescription());
            }

            game->getWindow()->draw(achievement.getIcon());

        }
    }
}

void PlayingState::setupAudio() {
    audioPlayer.insertMusic(MusicID::LEVEL, LEVEL_MUSIC_PATH, true, STANDARD_PITCH, DEF_MUSIC_VOLUME);
}
