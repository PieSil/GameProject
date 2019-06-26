/**
 * Project Game
 */


#include "GameLevel.h"

/**
 * GameLevel implementation
 */

GameLevel::GameLevel(std::unique_ptr<GameWindow> w) : frameTime(1. / FRAMERATE), window(std::move(w)) {
    hero = std::move(
            std::unique_ptr<Knight>(new Knight(window->getWindowSize().x / 2., window->getWindowSize().y / 2.)));
}

void GameLevel::updateLevel() {
    moveHero();
    window->update();
}

void GameLevel::moveHero() {

    //game updates ony if elapsed time is >= than fixed time-step chosen
    if (elapsed.asSeconds() >= frameTime) {
        hero->getSprite().setPosition(
                hero->getSprite().getPosition().x + hero->getMovementSpeed() * elapsed.asSeconds(),
                hero->getSprite().getPosition().y);
        hero->getSprite().setTextureRect(
                sf::IntRect(KNIGHT_WIDTH * hero->getMovingCounter(), KNIGHT_WIDTH * KNIGHT_MOV_ROW_SELECTOR,
                            KNIGHT_WIDTH,
                            KNIGHT_HEIGHT));
        if (!(hero->isFacingRight())) { //flip horizontally
            hero->getSprite().setScale(KNIGHT_SCALE * 1.f, KNIGHT_SCALE * 1.f);
            hero->setFacingRight(true);
        }


        hero->setMovingCounter(hero->getMovingCounter() + 1);

        if (hero->getMovingCounter() > 7) {
            hero->setMovingCounter(0);
        }

        //game updated, subtract fixed time-step and "reset" elapsed time
        //game will update again when elapsed equals the fixed time-step chosen
        elapsed -= sf::seconds(frameTime);
    }
    /*
        if (auto k = dynamic_cast<Knight *>(hero.get()))
            k->updateBehaviour();
    }
    */
}

void GameLevel::renderLevel() {
    //clears window:
    window->beginDraw();

    //drwas elements on window:
    window->draw(hero->getSprite());

    //displays window:
    window->endDraw();
}

void GameLevel::handleInput() {

}
