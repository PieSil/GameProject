//
// Created by Pietro on 2019-07-09.
//

#include "gtest/gtest.h"
#include "math.h"
#include "GameLevel.h"



TEST(CollisionsTest, CreateAttackHitbox) {

    GameLevel level;
    Hitbox testHitbox = level.createAttackHitbox(level.getHero().get());
    EXPECT_EQ(testHitbox.getLeftEdge().getPosition().x, level.getHero()->getAllPositions().rightEdgePosition.x);
    EXPECT_EQ(testHitbox.getUpperEdge().getPosition().y, level.getHero()->getAllPositions().upperEdgePosition.y);
    EXPECT_EQ(testHitbox.getLowerEdge().getPosition().y, level.getHero()->getAllPositions().lowerEdgePosition.y);


    level.getHero()->move(LEFT, 1);
    testHitbox = level.createAttackHitbox(level.getHero().get());
    EXPECT_EQ(testHitbox.getRightEdge().getPosition().x, level.getHero()->getAllPositions().leftEdgePosition.x);
    EXPECT_EQ(testHitbox.getUpperEdge().getPosition().y, level.getHero()->getAllPositions().upperEdgePosition.y);
    EXPECT_EQ(testHitbox.getLowerEdge().getPosition().y, level.getHero()->getAllPositions().lowerEdgePosition.y);
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

    Hitbox testHitbox = level.createAttackHitbox(hero);
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    hero->move(LEFT, 1); //move hero left so he's not facing the enemy
    testHitbox = level.createAttackHitbox(hero);
    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    hero->move(RIGHT,
               0); //switch hero to face right, now he should be facing the enemy but the enemy is 1 pixel too far to intersect with by the attackHitbox
    testHitbox = level.createAttackHitbox(hero);
    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    enemy->setPosition(hero->getAllPositions().spritePosition); //move the enemy back to hero's position

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

    testHitbox = level.createAttackHitbox(hero);
    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero left so that his right edge is exactly one pixel left of enemy's right edge
    hero->move(LEFT, 2);
    ASSERT_EQ(-1, hero->getAllPositions().rightEdgePosition.x - enemy->getAllPositions().rightEdgePosition.x);

    hero->move(RIGHT, 0); //set hero to face right, his attackHitbox should now intersect enemy's hitbox
    testHitbox = level.createAttackHitbox(hero);
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero down so that his upper edge is one pixel below enemy's lower edge
    hero->move(DOWN, hero->getHitbox().getHitbox().getSize().y / 2. +
                     enemy->getHitbox().getHitbox().getSize().y / 2 + 1);
    ASSERT_EQ(1, hero->getAllPositions().upperEdgePosition.y - enemy->getAllPositions().lowerEdgePosition.y);

    //attack hitbox should not intersect enemy's hitbox
    testHitbox = level.createAttackHitbox(hero);
    EXPECT_EQ(false, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

    //move hero up so that his upper edge overlaps enemy's lower edge
    hero->move(UP, 1);
    ASSERT_EQ(hero->getAllPositions().upperEdgePosition.y, enemy->getAllPositions().lowerEdgePosition.y);

    testHitbox = level.createAttackHitbox(hero);
    EXPECT_EQ(true, testHitbox.checkHitbox().intersects(enemy->getHitbox().checkHitbox()));

}



