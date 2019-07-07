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
                std::unique_ptr<Knight>(new Knight(4*TILE_SIZE.x, 6*TILE_SIZE.y)));
    } else if (heroT == WZRD) {
        hero = std::move(
                std::unique_ptr<Wizard>(new Wizard(4*TILE_SIZE.x, 6*TILE_SIZE.y)));
    } else {
        //TODO: throw exception
    }

    createMap();
    createView();


    enemies.push_back(std::unique_ptr<MeleeEnemy>(
            new MeleeEnemy(hero.get(), window->getWindowSize().x / 2. - 120 + 10, window->getWindowSize().y / 2.)));
}

void Game::updateGame() {

    if (elapsed.asSeconds() >= frameTime) { //game updates ony if elapsed time is >= than fixed time-step chosen

        handleInput(); //polls events from keyboard
        updateView();

        //updates physics
        updatePhysics(hero.get());
        updateEnemies();

        /*

        //check if physics works
        if (enemy->isOnGround()) {
            enemy->setVelocityY(JUMP_VELOCITY);
        }
         */

        //game updated, subtract fixed time-step and "reset" elapsed time
        //game will update again when elapsed equals the fixed time-step chosen
        elapsed -= sf::seconds(frameTime);
    }

    hero->animate();

    for (const auto &enemy : enemies) {
        enemy->animate();
    }

    //checkOnGround(hero.get());


    window->update();

}

void Game::moveHero(const Direction &direction) {

    detectCollisions(hero->move(direction, hero->getMovementSpeed() * elapsed.asSeconds()), hero.get());

    if (hero->isOnGround()) {
        updateView();
    }

}


void Game::renderLevel() const {
    //clears window:
    window->beginDraw();

    //draws hitboxes on window, needed to see if hitboxes correctly match the sprites
    //drawHitbox(hero->getHitbox());

    window->draw(gameMap);

    /*
    for (auto tile : gameMap.getTiles()) {
        drawHitbox(tile.getHitbox());
    }
    */

    //draws sprites on window:
    window->draw(hero->getSprite());

    for (const auto &enemy : enemies) {
        //drawHitbox(enemy->getHitbox());
        window->draw(enemy->getSprite());
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
        hero->isOnGround()) {
        hero->setOnGround(false);
        hero->setVelocityY(JUMP_VELOCITY);
        keyPressed = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        hero->attack();
        keyPressed = true;
    }

    if (!keyPressed && hero->getState() != ATTACKING) {
        hero->setState(IDLE);
    }
}

void Game::drawHitbox(const Hitbox &hitbox) const {
    window->draw(hitbox.getHitbox());

    window->draw(hitbox.getUpperEdge());
    window->draw(hitbox.getLowerEdge());
    window->draw(hitbox.getRightEdge());
    window->draw(hitbox.getLeftEdge());
}

void Game::updatePhysics(GameCharacter *character) {

    //moves character on Y axis based on its velocity
    //call moving entity method to bypass check on character state

    if (auto h = dynamic_cast<GameHero *>(character)) {
        detectCollisions(h->move(UP, h->getVelocityY()), h);
    } else {
        detectCollisions(character->MovingEntity::move(UP, character->getVelocityY()), character);
    }

        character->setVelocityY(character->getVelocityY() + GRAVITY);



//checks if the character is on ground or not
    //checkOnGround(character);

}

/*
void Game::checkOnGround(GameCharacter *character) {

    auto lowerEdge = character->getHitbox().checkLowerEdge();

    if (lowerEdge.intersects(
            ground.checkUpperEdge())) { //check if character's lowerEdge is touching ground's upper edge
        character->setOnGround(true);
    } else {
        character->setOnGround(false);
    }
}
*/

void Game::updateEnemies() {
    for (const auto &enemy : enemies) {

        updatePhysics(enemy.get()); //update enemy physics

        if (!(enemy->getHitbox().checkHitbox().intersects(
                hero->getHitbox().checkHitbox()))) { //if enemy hitbox is not touching hero hitbox

            detectCollisions(enemy->move(elapsed.asSeconds() *
                        enemy->getMovementSpeed()), enemy.get()); //use move method to move towards hero (if aggro is active)

        } else {
            enemy->setState(IDLE);
        }
    }
}

void Game::createView() {
    view = std::make_shared<sf::View>(sf::View(sf::Vector2f(hero->getSprite().getPosition()), sf::Vector2f(8*TILE_SIZE.x, 8*TILE_SIZE.y)));
    updateView();
}

void Game::updateView() {

    if (!(hero->getSprite().getPosition().x - view->getSize().x/2.< 0 || hero->getSprite().getPosition().x + view->getSize().x/2. > MAP_COLUMNS*TILE_SIZE.x)) {
        view->setCenter(hero->getSprite().getPosition().x, view->getCenter().y);
        window->setView(*view);
    }
}

void Game::createMap() {

    const int level[] = {
            3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9,9,9,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
            3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,6,0,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
            3,3,3,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,0,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,3,3,3,
            3,3,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,3,
            3,3,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,0,0,0,0,0,5,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,3,
            3,3,6,0,0,0,0,0,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,4,6,0,0,0,0,5,3,6,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,5,1,1,7,0,0,0,0,0,0,5,7,0,0,0,0,0,0,0,0,4,3,3,
            3,3,6,0,0,0,0,0,0,0,0,0,5,1,1,3,3,1,7,0,0,5,1,3,6,0,0,1,0,2,3,6,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,4,3,3,6,0,0,1,1,1,0,4,6,0,0,0,0,0,0,0,0,4,3,3,
            3,3,6,0,0,0,0,0,0,0,0,0,4,3,3,3,3,3,6,0,0,4,3,3,6,0,0,0,0,0,4,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,6,0,0,0,0,0,0,4,6,0,0,0,0,0,0,0,0,4,3,3,
            3,3,3,1,1,1,1,7,0,5,1,1,3,3,3,3,3,3,3,1,1,3,3,3,3,1,1,1,1,1,3,6,0,5,1,1,1,1,1,1,1,1,7,0,0,0,0,4,3,3,3,3,1,1,7,0,5,1,3,3,1,1,1,1,1,1,1,1,3,3,3,
            3,3,3,3,3,3,3,3,8,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8,3,3,3,3,3,3,3,3,3,3,8,8,8,8,4,3,3,3,3,3,3,3,8,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,

    };

    gameMap = Map(level,MAP_COLUMNS, MAP_ROWS);
    gameMap.load();
}

void Game::detectCollisions(const entityPositions prevPosition, GameCharacter *character) {

    sf::FloatRect intersection;

    if (!character->getHitbox().checkHitbox().intersects(gameMap.getVertices().getBounds())) {
        character->setPosition(prevPosition.spritePosition);
    }

    for (const auto& tile : gameMap.getTiles()) {


        if (character->getHitbox().checkHitbox().intersects(tile.getHitbox().checkHitbox(), intersection)) {


            if (prevPosition.rightEdgePosition.x <= tile.getHitbox().getLeftEdge().getPosition().x &&
                character->getAllPositions().rightEdgePosition.x > tile.getHitbox().getLeftEdge().getPosition().x) {
                character->setPosition(prevPosition.spritePosition.x, character->getSprite().getPosition().y);

            }

            if (prevPosition.leftEdgePosition.x >= tile.getHitbox().getRightEdge().getPosition().x &&
                character->getAllPositions().leftEdgePosition.x < tile.getHitbox().getRightEdge().getPosition().x) {
                character->setPosition(prevPosition.spritePosition.x, character->getSprite().getPosition().y);

            }

            if (prevPosition.upperEdgePosition.y >= tile.getHitbox().getLowerEdge().getPosition().y &&
                character->getAllPositions().upperEdgePosition.y < tile.getHitbox().getLowerEdge().getPosition().y) {
                character->setPosition(character->getSprite().getPosition().x, prevPosition.spritePosition.y);
                character->setVelocityY(0);

            }

            if (prevPosition.lowerEdgePosition.y <= tile.getHitbox().getUpperEdge().getPosition().y &&
                character->getAllPositions().lowerEdgePosition.y > tile.getHitbox().getUpperEdge().getPosition().y) {
                character->setPosition(character->getSprite().getPosition().x, prevPosition.spritePosition.y);
                character->setVelocityY(0);
                character->setOnGround(true);

            }
        }
    }
}
