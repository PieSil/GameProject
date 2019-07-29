//
// Created by Pietro on 2019-06-27.
//

#include "GameLevel.h"

GameLevel::GameLevel(Herotype heroT) {
    if (heroT == Herotype::KNGT) {
        hero = std::move(
                std::unique_ptr<Knight>(new Knight(4 * TILE_SIZE.x, 6 * TILE_SIZE.y)));

    } else if (heroT == Herotype::WZRD) {
        hero = std::move(
                std::unique_ptr<Wizard>(new Wizard(4 * TILE_SIZE.x, 6 * TILE_SIZE.y)));
    } else {
        //TODO: throw exception
    }

    enemies.emplace_back(std::unique_ptr<MeleeEnemy>(
            new MeleeEnemy(hero.get(), 14 * TILE_SIZE.x, 5 * TILE_SIZE.y)));

    enemies.emplace_back(std::unique_ptr<BossEnemy>(
            new BossEnemy(hero.get(), 7 * TILE_SIZE.x, 6 * TILE_SIZE.y)));

    createMap();

}


void GameLevel::createMap() {

    std::ifstream file("../GameAssets/Tileset/MapMatrix.txt");

    if (file.is_open()) {
        unsigned short i;
        unsigned short j;

        int level[MAP_ROWS * MAP_COLUMNS];

        for (i = 0; i < MAP_ROWS; i++) {
            for (j = 0; j < MAP_COLUMNS; j++) {

                file >> level[i * MAP_COLUMNS + j];
            }
        }

        gameMap = Map(level, MAP_COLUMNS, MAP_ROWS);
        gameMap.load();

    } else {
        std::cout << "\nCould not open map matrix file, map not loaded.\nTerminating the program." << std::endl;

        exit(EXIT_FAILURE);

    }

    /*
    const int level[] = {
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 9, 9, 9, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6, 0, 0, 0, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 0, 2, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 5, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 1, 1, 7, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 3, 3, 1, 7, 0, 0, 5, 1, 3, 6, 0, 0, 1, 0, 2, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 3, 3, 6, 0, 0, 1, 1, 1, 0, 4, 6, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3, 3, 3, 3, 6, 0, 0, 4, 3, 3, 6, 0, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 3, 3, 3, 6, 0, 0, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 3,
            3, 3, 3, 1, 1, 1, 1, 7, 0, 5, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 3, 6, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 7, 0, 0, 0, 0, 4, 3, 3, 3, 3, 1, 1, 7, 0, 5, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 8, 8, 8, 8, 4, 3, 3, 3, 3, 3, 3, 3, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,

    };
     */
}

const EntityPositions &GameLevel::detectMapCollisions(const EntityPositions &prevPosition, GameCharacter *character) {

    //if character is out of map put it back
    if (!character->getHitbox().checkHitbox().intersects(gameMap.getVertices().getBounds())) {
        character->setPosition(prevPosition.spritePosition);
    }

    //get the 8 tiles around the character and the tile it's standing in and check collisions with those:

    //[i][j] == [i*col + j]
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int tileColumn = (character->getAllPositions().gridPositionX + i);
            int tileRow = (character->getAllPositions().gridPositionY + j);
            int tileIndex = (tileRow * MAP_COLUMNS + tileColumn);

            //check out of bound
            if (tileIndex < 0) {
                tileIndex = 0;
            } else if (tileIndex >= (MAP_COLUMNS * MAP_ROWS)) {
                tileIndex = (MAP_ROWS * MAP_COLUMNS - 1);
            }


            Tile currentTile = gameMap.getTiles()[tileIndex];

            //only perform collision check if character's hitbox intersects current tile and tile is not walkable

            if(currentTile.isDeadly()) {
                if (character->getState() != EntityState::DYING && character->getState() != EntityState::DEAD)
                character->setState(EntityState::DYING);
            }

            if ((!currentTile.isWalkable()) &&
                character->getHitbox().checkHitbox().intersects(currentTile.getHitbox().checkHitbox())) {

                //if before movement character's upper edge was below of tile's lower edge and after movement
                //it's above of tile's lower edge then there's been a collision
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

                //if before movement character's right edge was left of tile's left edge and after movement
                //it's right of tile's left edge then there's been a collision
                if (prevPosition.rightEdgePosition.x <= currentTile.getHitbox().getLeftEdge().getPosition().x &&
                    character->getAllPositions().rightEdgePosition.x >
                    currentTile.getHitbox().getLeftEdge().getPosition().x) {

                    //move the character back on the x axis
                    character->setPosition(prevPosition.spritePosition.x, character->getSprite().getPosition().y);

                    if (auto e = dynamic_cast<Enemy *>(character)) {
                        if (e->isFacingRight())
                            character->jump();
                    }

                }

                //same reasoning as previous if statement
                if (prevPosition.leftEdgePosition.x >= currentTile.getHitbox().getRightEdge().getPosition().x &&
                    character->getAllPositions().leftEdgePosition.x <
                    currentTile.getHitbox().getRightEdge().getPosition().x) {

                    //move the character back
                    character->setPosition(prevPosition.spritePosition.x, character->getSprite().getPosition().y);

                    if (auto e = dynamic_cast<Enemy *>(character)) {
                        if (!e->isFacingRight())
                            character->jump();
                    }

                }

            }
        }
    }

    //if character moved on the y axis then it's not on ground
    if (prevPosition.spritePosition.y != character->getSprite().getPosition().y) {
        character->setOnGround(false);
    }

    return prevPosition;
}

const bool GameLevel::detectMapCollisions(std::unique_ptr<Projectile> &projectile) {

    bool toDelete = false;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int tileColumn = (projectile->getAllPositions().gridPositionX + i);
            int tileRow = (projectile->getAllPositions().gridPositionY + j);
            int tilePosition = (tileRow * MAP_COLUMNS + tileColumn);

            //check out of bound
            if (tilePosition < 0) {
                tilePosition = 0;
            } else if (tilePosition >= (MAP_COLUMNS * MAP_ROWS)) {
                tilePosition = MAP_ROWS * MAP_COLUMNS;
            }


            Tile currentTile = gameMap.getTiles()[tilePosition];

            if (!currentTile.isWalkable() &&
                projectile->getHitbox().checkHitbox().intersects(currentTile.getHitbox().checkHitbox())) {
                toDelete = true;
            }
        }
    }
    return toDelete;
}


void GameLevel::updateLevel(const float &elapsedTime) {
    updateHero();
    updateEnemies(elapsedTime);
    updateProjectiles(elapsedTime);

}

void GameLevel::moveCharacter(GameHero *hero, const Direction &direction, const float &distance) {
    const EntityPositions prevPosition = detectMapCollisions(hero->move(direction, distance), hero);
    hero->incrDistanceWalked(abs(hero->getAllPositions().spritePosition.x - prevPosition.spritePosition.x));
}

void GameLevel::moveCharacter(Enemy *enemy, const float &distance) {
    detectMapCollisions(enemy->move(distance), enemy);
}

void GameLevel::updateHero() {
    updatePhysics(hero.get());
    hero->updateStatus();
}

void GameLevel::updatePhysics(GameCharacter *character) {

    //moves character on Y axis based on its velocity
    //call moving entity method to bypass check on character state

    detectMapCollisions(character->MovingEntity::move(Direction::UP, character->getVelocityY()), character);

    character->setVelocityY(character->getVelocityY() + GRAVITY);

}

void GameLevel::updateEnemies(const float &elapsedTime) {
    auto enemy = enemies.begin();


    while (!enemies.empty() && enemy != enemies.end()) {

        updatePhysics(enemy->get()); //update enemy physics
        //if enemy hitbox is not touching hero hitbox

        (*enemy)->updateStatus();
        moveCharacter(enemy->get(), (*enemy)->getMovementSpeed() * elapsedTime);
        updateCombat(enemy->get());

        /*
        enemy->updateAggro();

        enemy->attack();

        moveCharacter(enemy.get(), enemy->getMovementSpeed() * elapsedTime);
         */

        if ((*enemy)->getState() == EntityState::DEAD) {
            destroy(*enemy);
            //projectiles.erase(projectile);

        } else
            enemy++;

    }
}

void GameLevel::animateCharacters() {
    hero->animate();
    for (auto &enemy : enemies) {
        enemy->animate();
    }
}

void GameLevel::updateCombat(GameHero *hero) {

    std::pair<bool, Hitbox> attackPair = hero->attack();

    if (attackPair.first) { //if hero has started an attack

        if (hero->getState() == EntityState::MELEE) {

            Hitbox attackHitbox = attackPair.second;

            for (const auto &enemy :enemies) {
                if (attackPair.second.checkHitbox().intersects(enemy->getHitbox().checkHitbox())) {
                    //TODO: do damage to enemy
                    if (enemy->getDamaged(hero->getStrength())) { // if enemy got damaged
                        if (enemy->getState() == EntityState::DYING) { //and it's dying
                            hero->incrEnemiesKilled();//increase the counter of enemies killed by the hero
                            if (typeid(*(enemy.get())) == typeid(BossEnemy))
                                hero->setBossKilled();
                        }
                    }
                }
            }

        } else {
            projectiles.push_back(std::unique_ptr<Fireball>(new Fireball(attackPair.second, hero)));
        }
    }
}


void GameLevel::updateCombat(Enemy *enemy) {

    std::pair<bool, Hitbox> attackPair = enemy->updateCombat();

    if (attackPair.first) {

        if (enemy->getState() == EntityState::MELEE) {


            if (attackPair.second.checkHitbox().intersects(hero->getHitbox().checkHitbox())) {
                //TODO: damage the hero
                hero->getDamaged(enemy->getStrength());
            }

        } else {
            //TODO: shoot projectile
            projectiles.push_back(std::unique_ptr<Fireball>(new Fireball(attackPair.second, enemy)));
        }
    }
}


const Hitbox GameLevel::createAttackHitbox(GameCharacter *character) {
    Hitbox attackHitbox;

    if (character->isFacingRight()) //if character is facing right create hitbox to its right

        //x position of the hitbox is set so that attackHitbox's left edge overlaps with chracter's hitbox right edge
        attackHitbox = Hitbox(
                sf::Vector2f(character->getAllPositions().rightEdgePosition.x + character->getAttackRange() / 2.,
                             character->getAllPositions().spritePosition.y), character->getAttackRange(),
                abs(character->getAllPositions().upperEdgePosition.y -
                    character->getAllPositions().lowerEdgePosition.y));

    else //else create hitbox to its left

        //x position of the hitbox is set so that attackHitbox's right edge overlaps with chracter's hitbox left edge
        attackHitbox = Hitbox(
                sf::Vector2f(character->getAllPositions().leftEdgePosition.x - character->getAttackRange() / 2.,
                             character->getAllPositions().spritePosition.y), character->getAttackRange(),
                (abs(character->getAllPositions().upperEdgePosition.y -
                     character->getAllPositions().lowerEdgePosition.y)));


    return attackHitbox;
}


/*
void GameLevel::createProjectile(GameHero *hero, const bool &isFireball) {

    if (isFireball) {
        projectiles.push_back(std::unique_ptr<Fireball>(new Fireball(hero->getAllPositions().spritePosition.x,
                                                                     hero->getAllPositions().spritePosition.y,
                                                                     hero->isFacingRight())));
    }

}


void GameLevel::createProjectile(Enemy *enemy, const bool &isFireball) {

    if (isFireball) {
        projectiles.emplace_back(std::unique_ptr<Fireball>(new Fireball(enemy->getAllPositions().spritePosition.x,
                                                                        enemy->getAllPositions().spritePosition.y,
                                                                        enemy->isFacingRight(), false)));
    }

}
*/

void GameLevel::updateProjectiles(const float &elapsedTime) {

    auto projectile = projectiles.begin();
    auto end = projectiles.end();


    while (!projectiles.empty() && projectile != projectiles.end()) {

        bool toDelete = false;

        (*projectile)->move((*projectile)->getMovementSpeed() * elapsedTime);

        (*projectile)->animate();

        if ((*projectile)->isFriendly()) {
            for (const auto &enemy : enemies) {
                if ((*projectile)->getHitbox().checkHitbox().intersects(enemy->getHitbox().checkHitbox())) {
                    (*projectile)->characterCollision(enemy.get());
                    //destroyProjectile(*projectile);
                    toDelete = true;
                }
            }

        } else {
            if ((*projectile)->getHitbox().checkHitbox().intersects(hero->getHitbox().checkHitbox())) {
                (*projectile)->characterCollision(hero.get());
                //destroyProjectile(*projectile);
                toDelete = true;
            }
        }

        if (!toDelete) {
            toDelete = detectMapCollisions(*projectile);
        }

        if (toDelete) {
            destroy(*projectile);
            //projectiles.erase(projectile);

        } else
            projectile++;

    }


}

void GameLevel::destroy(std::unique_ptr<Projectile> &projectile) {

    auto itr = std::find(projectiles.begin(), projectiles.end(), projectile);

    projectiles.erase(itr);

}


void GameLevel::destroy(std::unique_ptr<Enemy> &enemy) {
    auto itr = std::find(enemies.begin(), enemies.end(), enemy);
    enemies.erase(itr);
}

//ONLY USED FOR UNIT TESTING
GameLevel::GameLevel() : gameMap(Map()) {
    hero = std::move(
            std::unique_ptr<Knight>(new Knight(0, 0)));

    enemies.push_back(std::unique_ptr<MeleeEnemy>(
            new MeleeEnemy(hero.get(), 0, 0)));

}


