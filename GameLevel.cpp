//
// Created by Pietro on 2019-06-27.
//

#include "GameLevel.h"

GameLevel::GameLevel(Herotype heroT) {
    if (heroT == KNGT) {
        hero = std::move(
                std::unique_ptr<Knight>(new Knight(4 * TILE_SIZE.x, 6 * TILE_SIZE.y)));
    } else if (heroT == WZRD) {
        hero = std::move(
                std::unique_ptr<Wizard>(new Wizard(4 * TILE_SIZE.x, 6 * TILE_SIZE.y)));
    } else {
        //TODO: throw exception
    }

    enemies.push_back(std::unique_ptr<MeleeEnemy>(
            new MeleeEnemy(hero.get(), 14 * TILE_SIZE.x, 5 * TILE_SIZE.y)));

    enemies.push_back(std::unique_ptr<BossEnemy>(
            new BossEnemy(hero.get(), 7 * TILE_SIZE.x, 6 * TILE_SIZE.y)));

    createMap();

}

void GameLevel::createMap() {

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

void GameLevel::detectCollisions(const entityPositions &prevPosition, GameCharacter *character) {

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

void GameLevel::moveCharacter(GameHero *hero, const Direction &direction, const float &distance) {
    detectCollisions(hero->move(direction, distance), hero);
}

void GameLevel::moveCharacter(Enemy *enemy, const float &distance) {
    detectCollisions(enemy->move(distance), enemy);
}

void GameLevel::moveCharacter(GameCharacter *character, const Direction &direction, const float &distance) {
    detectCollisions(character->move(direction, distance), character);
}



void GameLevel::updatePhysics(GameCharacter *character) {

    //moves character on Y axis based on its velocity
    //call moving entity method to bypass check on character state
    //TODO: find a better way to bypass check on character state

    detectCollisions(character->MovingEntity::move(UP, character->getVelocityY()), character);

    character->setVelocityY(character->getVelocityY() + GRAVITY);

}

void GameLevel::updateLevel(const float &elapsedTime) {
    updateHero();
    updateEnemies(elapsedTime);

}

void GameLevel::updateEnemies(const float &elapsedTime) {
    for (const auto &enemy : enemies) {

        updatePhysics(enemy.get()); //update enemy physics
        //if enemy hitbox is not touching hero hitbox

        detectCollisions(enemy->updateBehaviour(enemy->getMovementSpeed() * elapsedTime), enemy.get());

        /*
        enemy->updateAggro();

        enemy->attack();

        moveCharacter(enemy.get(), enemy->getMovementSpeed() * elapsedTime);
         */

    }
}

void GameLevel::updateHero() {
    updatePhysics(hero.get());
}

void GameLevel::animateCharacters() {
    hero->animate();
    for (auto &enemy : enemies) {
        enemy->animate();
    }
}

