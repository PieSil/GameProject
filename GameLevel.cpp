/**
 * Project Game
 */


#include "GameLevel.h"

/**
 * GameLevel implementation
 */

GameLevel::GameLevel(std::unique_ptr<GameWindow> w) : window(std::move(w)){
    hero = std::move(std::unique_ptr<Knight>(new Knight(window->getWindowSize().x/2., window->getWindowSize().y/2.)));
}

void GameLevel::updateLevel() {
    window->update();
    moveHero();
}

void GameLevel::moveHero() {
    if (auto k = dynamic_cast<Knight*>(hero.get()))
    k->updateBehaviour();
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
