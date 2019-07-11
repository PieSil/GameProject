//
// Created by Pietro on 2019-07-09.
//

#include "gtest/gtest.h"
#include "math.h"
#include "GameLevel.h"



TEST(CollisionsTest, CreateAttackHitbox) {

    GameLevel level;
    Hitbox testHitbox = level.getHero()->attack(true).second;
    level.getHero()->setState(IDLE);

    ASSERT_EQ(testHitbox.getLeftEdge().getPosition().x, level.getHero()->getAllPositions().rightEdgePosition.x);
    ASSERT_EQ(testHitbox.getUpperEdge().getPosition().y, level.getHero()->getAllPositions().upperEdgePosition.y);
    ASSERT_EQ(testHitbox.getLowerEdge().getPosition().y, level.getHero()->getAllPositions().lowerEdgePosition.y);


    level.getHero()->move(LEFT, 1);
    level.getHero()->setState(IDLE);
    testHitbox = level.getHero()->attack(true).second;
    level.getHero()->setState(IDLE);

    ASSERT_EQ(testHitbox.getRightEdge().getPosition().x, level.getHero()->getAllPositions().leftEdgePosition.x);
    ASSERT_EQ(testHitbox.getUpperEdge().getPosition().y, level.getHero()->getAllPositions().upperEdgePosition.y);
    ASSERT_EQ(testHitbox.getLowerEdge().getPosition().y, level.getHero()->getAllPositions().lowerEdgePosition.y);
}

TEST(CollisionsTest, HitboxSize) {
    GameLevel level;
    auto hero = level.getHero().get();
    hero->setState(IDLE);
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

    hero->setState(IDLE);
    Hitbox testHitbox = hero->attack(true).second;
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    hero->setState(IDLE);;
    hero->move(LEFT, 1); //move hero left so he's not facing the enemy

    hero->setState(IDLE);
    testHitbox = hero->attack(true).second;
    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    hero->setState(IDLE);;
    hero->move(RIGHT, 0); //switch hero to face right, now he should be facing the enemy but the enemy is 1 pixel too far to intersect with by the attackHitbox

    hero->setState(IDLE);
    testHitbox = hero->attack(true).second;

    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    enemy->setPosition(hero->getAllPositions().spritePosition); //move the enemy back to hero's position

    hero->setState(IDLE);;
    //move hero so that his right edge is exactly one pixel right of enemy's right edge
    if (hero->getAllPositions().rightEdgePosition.x >= enemy->getAllPositions().rightEdgePosition.x) {
        hero->move(LEFT,
                   1 + hero->getAllPositions().rightEdgePosition.x - enemy->getAllPositions().rightEdgePosition.x);

        //set the hero to face  right
        hero->move(RIGHT, 0);
    } else {
        hero->move(RIGHT,
                   1 + enemy->getAllPositions().rightEdgePosition.x - hero->getAllPositions().rightEdgePosition.x);
    }

    //check if hero has been correctly positioned
    ASSERT_EQ(1, hero->getAllPositions().rightEdgePosition.x - enemy->getAllPositions().rightEdgePosition.x);

    hero->setState(IDLE);
    testHitbox = hero->attack(true).second;

    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero left so that his right edge is exactly one pixel left of enemy's right edge
    hero->setState(IDLE);
    hero->move(LEFT, 2);

    ASSERT_EQ(-1, hero->getAllPositions().rightEdgePosition.x - enemy->getAllPositions().rightEdgePosition.x);

    hero->setState(IDLE);
    hero->move(RIGHT, 0); //set hero to face right, his attackHitbox should now intersect enemy's hitbox

    hero->setState(IDLE);
    testHitbox = hero->attack(true).second;
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero down so that his upper edge is one pixel below enemy's lower edge
    hero->setState(IDLE);
    hero->move(DOWN, hero->getHitbox().getHitbox().getSize().y / 2. +
                     enemy->getHitbox().getHitbox().getSize().y / 2 + 1);
    ASSERT_EQ(1, hero->getAllPositions().upperEdgePosition.y - enemy->getAllPositions().lowerEdgePosition.y);

    //attack hitbox should not intersect enemy's hitbox
    hero->setState(IDLE);
    testHitbox = hero->attack(true).second;
    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero up so that his upper edge overlaps enemy's lower edge
    hero->setState(IDLE);
    hero->move(UP, 1);
    ASSERT_EQ(hero->getAllPositions().upperEdgePosition.y, enemy->getAllPositions().lowerEdgePosition.y);

    hero->setState(IDLE);
    testHitbox = hero->attack(true).second;
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

}



