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
                std::unique_ptr<Knight>(new Knight(4 * TILE_SIZE.x, 6 * TILE_SIZE.y)));
    } else if (heroT == WZRD) {
        hero = std::move(
                std::unique_ptr<Wizard>(new Wizard(4 * TILE_SIZE.x, 6 * TILE_SIZE.y)));
    } else {
        //TODO: throw exception
    }

    createMap();
    createView();

    enemies.push_back(std::unique_ptr<MeleeEnemy>(
            new MeleeEnemy(hero.get(), 14 * TILE_SIZE.x, 5 * TILE_SIZE.y)));
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
                                         enemy->getMovementSpeed()),
                             enemy.get()); //use move method to move towards hero (if aggro is active)

        } else {
            enemy->setState(IDLE);
        }
    }
}

void Game::createView() {
    view = std::make_shared<sf::View>(
            sf::View(sf::Vector2f(hero->getSprite().getPosition()), sf::Vector2f(8 * TILE_SIZE.x, 8 * TILE_SIZE.y)));
    updateView();
}

void Game::updateView() {

    if (!(hero->getSprite().getPosition().x - view->getSize().x / 2. < 0 ||
          hero->getSprite().getPosition().x + view->getSize().x / 2. > MAP_COLUMNS * TILE_SIZE.x)) {
        view->setCenter(hero->getSprite().getPosition().x, view->getCenter().y);
        window->setView(*view);
    }
}

void Game::createMap() {

    const int level[] = {
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 9, 9, 9, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6, 0, 0, 0, 4, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 0, 2, 9, 9, 9, 9, 9, 9, 9, 9,
            9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 5, 3, 6, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 1, 1, 7, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 3, 3, 1, 7, 0, 0, 5, 1, 3, 6, 0, 0, 1, 0, 2, 3, 6, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 3, 3, 6, 0, 0, 1, 1, 1, 0, 4, 6, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3, 3, 3, 3, 6, 0, 0, 4, 3, 3, 6, 0, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 3, 3, 3, 6, 0, 0, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 3, 1, 1, 1, 1, 7, 0, 5, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 3, 6, 0, 5, 1, 1,
            1, 1, 1, 1, 1, 1, 7, 0, 0, 0, 0, 4, 3, 3, 3, 3, 1, 1, 7, 0, 5, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 8, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 8, 8, 8, 8, 4, 3, 3, 3, 3, 3, 3, 3, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,

    };

    gameMap = Map(level, MAP_COLUMNS, MAP_ROWS);
    gameMap.load();
}

void Game::detectCollisions(const entityPositions prevPosition, GameCharacter *character) {

    //if character is out of map put it back
    if (!character->getHitbox().checkHitbox().intersects(gameMap.getVertices().getBounds())) {
        character->setPosition(prevPosition.spritePosition);
    }

    //get the 8 tiles around the character and the tile it's standing in and check collsisions with those:

    //[i][j] == [i*col + j]
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int tileColumn = (character->getAllPositions().gridPositionX + i);
            int tileRow = (character->getAllPositions().gridPositionY + j);
            int tilePosition = (tileRow * MAP_COLUMNS + tileColumn);

            //check out of bound
            if (tilePosition < 0) {
                tilePosition = 0;
            } else if (tilePosition >= (MAP_COLUMNS * MAP_ROWS)) {
                tilePosition = MAP_ROWS * MAP_COLUMNS;
            }


            Tile currentTile = gameMap.getTiles()[tilePosition];

            //only perform collision check if character's hitbox intersects current tile
            if (character->getHitbox().checkHitbox().intersects(currentTile.getHitbox().checkHitbox())) {



                if (prevPosition.rightEdgePosition.x <= currentTile.getHitbox().getLeftEdge().getPosition().x &&
                    character->getAllPositions().rightEdgePosition.x >
                    currentTile.getHitbox().getLeftEdge().getPosition().x) {
                    //if before movement character's right edge was left of tile's left edge and after movement
                    //it's right of tile's left edge then there's been a collision

                    //move the character back on the x axis
                    character->setPosition(prevPosition.spritePosition.x, character->getSprite().getPosition().y);

                }

                //same reasoning as previous if statement
                if (prevPosition.leftEdgePosition.x >= currentTile.getHitbox().getRightEdge().getPosition().x &&
                    character->getAllPositions().leftEdgePosition.x <
                    currentTile.getHitbox().getRightEdge().getPosition().x) {

                    //move the character back
                    character->setPosition(prevPosition.spritePosition.x, character->getSprite().getPosition().y);

                }

                //same reasoning as previous if statement on the x axis
                if (prevPosition.upperEdgePosition.y >= currentTile.getHitbox().getLowerEdge().getPosition().y &&
                    character->getAllPositions().upperEdgePosition.y <
                    currentTile.getHitbox().getLowerEdge().getPosition().y) {

                    //move the character back on the y axis and set its velocityY to 0
                    character->setPosition(character->getSprite().getPosition().x, prevPosition.spritePosition.y);
                    character->setVelocityY(0);

                }

                //same reasoning as previous if statement
                if (prevPosition.lowerEdgePosition.y <= currentTile.getHitbox().getUpperEdge().getPosition().y &&
                    character->getAllPositions().lowerEdgePosition.y >
                    currentTile.getHitbox().getUpperEdge().getPosition().y) {

                    //move the character back on the y axis, set its velocityY to 0 and set it on ground
                    character->setPosition(character->getSprite().getPosition().x, prevPosition.spritePosition.y);
                    character->setVelocityY(0);
                    character->setOnGround(true);
                }

            }
        }
    }

    //if character moved on the y axis then it's not on ground
    if (prevPosition.spritePosition.y != character->getSprite().getPosition().y) {
        character->setOnGround(false);
    }
}
