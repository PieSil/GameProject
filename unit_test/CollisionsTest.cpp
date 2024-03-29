//
// Created by Pietro on 2019-07-09.
//

#include "gtest/gtest.h"
#include <math.h>
#include <algorithm>
#include "GameLevel.h"



TEST(CollisionsTest, AttackHitbox) {

    GameLevel level;
    Hitbox testHitbox = level.getHero()->attack(true).second;
    level.getHero()->setState(EntityState::IDLE);

    ASSERT_EQ(testHitbox.getLeftEdge().getPosition().x, level.getHero()->getAllPositions().rightEdgePosition.x);
    ASSERT_EQ(testHitbox.getUpperEdge().getPosition().y, level.getHero()->getAllPositions().upperEdgePosition.y);
    ASSERT_EQ(testHitbox.getLowerEdge().getPosition().y, level.getHero()->getAllPositions().lowerEdgePosition.y);


    level.getHero()->move(Direction::LEFT, 1);
    level.getHero()->setState(EntityState::IDLE);
    testHitbox = level.getHero()->attack(true).second;
    level.getHero()->setState(EntityState::IDLE);

    ASSERT_EQ(testHitbox.getRightEdge().getPosition().x, level.getHero()->getAllPositions().leftEdgePosition.x);
    ASSERT_EQ(testHitbox.getUpperEdge().getPosition().y, level.getHero()->getAllPositions().upperEdgePosition.y);
    ASSERT_EQ(testHitbox.getLowerEdge().getPosition().y, level.getHero()->getAllPositions().lowerEdgePosition.y);
}

TEST(CollisionsTest, AttackHitboxSize) {
    GameLevel level;
    auto hero = level.getHero().get();
    hero->setState(EntityState::IDLE);
    Hitbox testHitbox = hero->attack(true).second;
    EXPECT_EQ(hero->getAttackRange(), abs(testHitbox.getRightEdge().getPosition().x - testHitbox.getLeftEdge().getPosition().x));
}

TEST(CollisionTest, EnemyIntersection) {
    GameLevel level;
    auto hero = level.getHero().get();
    hero->setPosition(0, 0);
    const auto &enemy = level.getEnemies().begin()->get();

    //set enemy position so that only his hitbox's left edge is in hero's attack range
    enemy->setPosition(hero->getHitbox().getHitbox().getSize().x / 2. + (hero->getAttackRange() - 1) +
                       enemy->getHitbox().getHitbox().getSize().x / 2., 0);

    //check if enemy has been correctly positioned
    ASSERT_EQ(hero->getAllPositions().rightEdgePosition.x + hero->getAttackRange() - 1,
              enemy->getAllPositions().leftEdgePosition.x);

    hero->setState(EntityState::IDLE);
    Hitbox testHitbox = hero->attack(true).second;
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    hero->setState(EntityState::IDLE);;
    hero->move(Direction::LEFT, 1); //move hero left so he's not facing the enemy

    hero->setState(EntityState::IDLE);
    testHitbox = hero->attack(true).second;
    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    hero->setState(EntityState::IDLE);;
    hero->move(Direction::RIGHT, 0); //switch hero to face right, now he should be facing the enemy but the enemy is 1 pixel too far to intersect with by the attackHitbox

    hero->setState(EntityState::IDLE);
    testHitbox = hero->attack(true).second;

    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    enemy->setPosition(hero->getAllPositions().spritePosition); //move the enemy back to hero's position

    hero->setState(EntityState::IDLE);;
    //move hero so that his right edge is exactly one pixel right of enemy's right edge
    if (hero->getAllPositions().rightEdgePosition.x >= enemy->getAllPositions().rightEdgePosition.x) {
        hero->move(Direction::LEFT,
                   1 + hero->getAllPositions().rightEdgePosition.x - enemy->getAllPositions().rightEdgePosition.x);

        //set the hero to face  right
        hero->move(Direction::RIGHT, 0);
    } else {
        hero->move(Direction::RIGHT,
                   1 + enemy->getAllPositions().rightEdgePosition.x - hero->getAllPositions().rightEdgePosition.x);
    }

    //check if hero has been correctly positioned
    ASSERT_EQ(1, hero->getAllPositions().rightEdgePosition.x - enemy->getAllPositions().rightEdgePosition.x);

    hero->setState(EntityState::IDLE);
    testHitbox = hero->attack(true).second;

    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero left so that his right edge is exactly one pixel left of enemy's right edge
    hero->setState(EntityState::IDLE);
    hero->move(Direction::LEFT, 2);

    ASSERT_EQ(-1, hero->getAllPositions().rightEdgePosition.x - enemy->getAllPositions().rightEdgePosition.x);

    hero->setState(EntityState::IDLE);
    hero->move(Direction::RIGHT, 0); //set hero to face right, his attackHitbox should now intersect enemy's hitbox

    hero->setState(EntityState::IDLE);
    testHitbox = hero->attack(true).second;
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero down so that his upper edge is one pixel below enemy's lower edge
    hero->setState(EntityState::IDLE);
    hero->move(Direction::DOWN, hero->getHitbox().getHitbox().getSize().y / 2. +
                     enemy->getHitbox().getHitbox().getSize().y / 2 + 1);
    ASSERT_EQ(1, hero->getAllPositions().upperEdgePosition.y - enemy->getAllPositions().lowerEdgePosition.y);

    //attack hitbox should not intersect enemy's hitbox
    hero->setState(EntityState::IDLE);
    testHitbox = hero->attack(true).second;
    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero up so that his upper edge overlaps enemy's lower edge
    hero->setState(EntityState::IDLE);
    hero->move(Direction::UP, 1);
    ASSERT_EQ(hero->getAllPositions().upperEdgePosition.y, enemy->getAllPositions().lowerEdgePosition.y);

    hero->setState(EntityState::IDLE);
    testHitbox = hero->attack(true).second;
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

}


TEST(CollisionsTest, TileCollision) {
    GameLevel level;
    auto hero = level.getHero().get();
    hero->setPosition(0, 0);
    Tile testTile(sf::Vector2f(0, 0), 1);

    std::vector<Tile> tiles;
    tiles.push_back(testTile);
    level.setMapTiles(tiles);

    hero->setPosition(TILE_SIZE.x/2 + hero->getHitbox().getHitbox().getSize().x/2., hero->getSprite().getPosition().y);
    EXPECT_EQ(false, hero->getHitbox().checkHitbox().intersects(testTile.getHitbox().checkHitbox()));

    sf::Vector2f prevPosition = hero->getSprite().getPosition();

    level.detectMapCollisions(hero->move(Direction::LEFT, 1), hero, true);
    EXPECT_EQ(prevPosition, hero->getSprite().getPosition());

    tiles.clear();

    Tile testEmpty(sf::Vector2f(0, 0), 0);
    tiles.push_back(testEmpty);
    level.setMapTiles(tiles);

    prevPosition = hero->getSprite().getPosition();

    level.detectMapCollisions(hero->move(Direction::LEFT, 1), hero, true);
    EXPECT_EQ(prevPosition.x -1, hero->getSprite().getPosition().x);

    tiles.clear();

    Tile testSpikes(sf::Vector2f(0, 0), 8);
    tiles.push_back(testSpikes);
    level.setMapTiles(tiles);

    level.detectMapCollisions(hero->move(Direction::LEFT, 0), hero, true);
    EXPECT_EQ(EntityState::DYING, hero->getState());

}
