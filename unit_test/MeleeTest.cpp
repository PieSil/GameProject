//
// Created by Pietro on 2019-06-29.
//

#include "gtest/gtest.h"
#include "MeleeEnemy.h"
#include "gameValues.h"
#include <SFML/Graphics.hpp>


//Knight(float x, float y, float str = DEF_GAMEHERO_STRENGTH, bool onf = false, float h = DEF_GAMEHERO_HEALTH, bool facingR = true, float s = HERO_SPEED);

TEST(MeleeTest, Constructor) {
    MeleeEnemy m(5, 0);
    EXPECT_EQ(5, m.getSprite().getPosition().x);
    EXPECT_EQ(0, m.getSprite().getPosition().y);
    EXPECT_EQ(DEF_ENEMY_STRENGTH, m.getStrength());
    EXPECT_EQ(false, m.isParalyzed());
    EXPECT_EQ(false, m.isOnFire());
    EXPECT_EQ(DEF_ENEMY_HEALTH, m.getHealth());
    EXPECT_EQ(true, m.isFacingRight());
    EXPECT_EQ(ENEMY_SPEED, m.getMovementSpeed());
    EXPECT_EQ(false, m.isAggro());
}

TEST(MeleeTest, NotDefStrength) {
    MeleeEnemy m(5, 0, 25.);
    EXPECT_EQ(5, m.getSprite().getPosition().x);
    EXPECT_EQ(0, m.getSprite().getPosition().y);
    EXPECT_EQ(25., m.getStrength());
    EXPECT_EQ(false, m.isParalyzed());
    EXPECT_EQ(false, m.isOnFire());
    EXPECT_EQ(DEF_ENEMY_HEALTH, m.getHealth());
    EXPECT_EQ(true, m.isFacingRight());
    EXPECT_EQ(ENEMY_SPEED, m.getMovementSpeed());
    EXPECT_EQ(false, m.isAggro());
}

TEST(MeleeTest, NegativeStrength) {
    MeleeEnemy m(5, 0, -25.);
    EXPECT_EQ(5, m.getSprite().getPosition().x);
    EXPECT_EQ(0, m.getSprite().getPosition().y);
    EXPECT_EQ(25., m.getStrength());
    EXPECT_EQ(false, m.isParalyzed());
    EXPECT_EQ(false, m.isOnFire());
    EXPECT_EQ(DEF_ENEMY_HEALTH, m.getHealth());
    EXPECT_EQ(true, m.isFacingRight());
    EXPECT_EQ(ENEMY_SPEED, m.getMovementSpeed());
    EXPECT_EQ(false, m.isAggro());
}


TEST(MeleeTest, IsOnFire) {
    MeleeEnemy m(-5, 0, 25., false, true);
    EXPECT_EQ(-5, m.getSprite().getPosition().x);
    EXPECT_EQ(0, m.getSprite().getPosition().y);
    EXPECT_EQ(25., m.getStrength());
    EXPECT_EQ(false, m.isParalyzed());
    EXPECT_EQ(true, m.isOnFire());
    EXPECT_EQ(DEF_ENEMY_HEALTH, m.getHealth());
    EXPECT_EQ(true, m.isFacingRight());
    EXPECT_EQ(ENEMY_SPEED, m.getMovementSpeed());
    EXPECT_EQ(false, m.isAggro());

}


TEST(MeleeTest, NotDefHealth) {
    MeleeEnemy m(0, -5, 2., false, false, 540.);
    EXPECT_EQ(0, m.getSprite().getPosition().x);
    EXPECT_EQ(-5, m.getSprite().getPosition().y);
    EXPECT_EQ(2., m.getStrength());
    EXPECT_EQ(false, m.isParalyzed());
    EXPECT_EQ(false, m.isOnFire());
    EXPECT_EQ(540., m.getHealth());
    EXPECT_EQ(true, m.isFacingRight());
    EXPECT_EQ(ENEMY_SPEED, m.getMovementSpeed());
    EXPECT_EQ(false, m.isAggro());
}

TEST(MeleeTest, NegativeHealth) {
    MeleeEnemy m(0, -5, 2., false, false, -540.);
    EXPECT_EQ(0, m.getSprite().getPosition().x);
    EXPECT_EQ(-5, m.getSprite().getPosition().y);
    EXPECT_EQ(2., m.getStrength());
    EXPECT_EQ(false, m.isParalyzed());
    EXPECT_EQ(false, m.isOnFire());
    EXPECT_EQ(540., m.getHealth());
    EXPECT_EQ(true, m.isFacingRight());
    EXPECT_EQ(ENEMY_SPEED, m.getMovementSpeed());
    EXPECT_EQ(false, m.isAggro());
}


TEST(MeleeTest, IsFacingLeft) {
    MeleeEnemy m(0, -5, 5.,false, false, DEF_ENEMY_HEALTH, false);
    EXPECT_EQ(0, m.getSprite().getPosition().x);
    EXPECT_EQ(-5, m.getSprite().getPosition().y);
    EXPECT_EQ(5., m.getStrength());
    EXPECT_EQ(false, m.isParalyzed());
    EXPECT_EQ(false, m.isOnFire());
    EXPECT_EQ(DEF_ENEMY_HEALTH, m.getHealth());
    EXPECT_EQ(false, m.isFacingRight());
    EXPECT_EQ(ENEMY_SPEED, m.getMovementSpeed());
    EXPECT_EQ(false, m.isAggro());
}

TEST(MeleeTest, MovementSpeed) {
    MeleeEnemy m(0, -5, DEF_ENEMY_STRENGTH, false, false, DEF_ENEMY_HEALTH, false, 10.);
    EXPECT_EQ(0, m.getSprite().getPosition().x);
    EXPECT_EQ(-5, m.getSprite().getPosition().y);
    EXPECT_EQ(DEF_ENEMY_STRENGTH, m.getStrength());
    EXPECT_EQ(false, m.isParalyzed());
    EXPECT_EQ(false, m.isOnFire());
    EXPECT_EQ(DEF_ENEMY_HEALTH, m.getHealth());
    EXPECT_EQ(false, m.isFacingRight());
    EXPECT_EQ(10., m.getMovementSpeed());
    EXPECT_EQ(false, m.isAggro());
}

TEST(MeleeTest, Assigment) {
    MeleeEnemy m(-5, 3, DEF_ENEMY_STRENGTH, true, true, 32.15, true, 5.);
    m.setAggro(true);
    MeleeEnemy newM = m;
    EXPECT_EQ(newM.getSprite().getPosition().x, m.getSprite().getPosition().x);
    EXPECT_EQ(newM.getSprite().getPosition().y, m.getSprite().getPosition().y);
    EXPECT_EQ(newM.getStrength(), m.getStrength());
    EXPECT_EQ(false, newM.isParalyzed());
    EXPECT_EQ(newM.isOnFire(), m.isOnFire());
    EXPECT_EQ(newM.getHealth(), m.getHealth());
    EXPECT_EQ(newM.isFacingRight(), m.isFacingRight());
    EXPECT_EQ(newM.getMovementSpeed(), m.getMovementSpeed());
    EXPECT_EQ(false, newM.isAggro());

}

TEST(MeleeTest, Copy) {
    MeleeEnemy m(5, 0, DEF_ENEMY_STRENGTH, true, true, 25., false, 0.);
    m.setAggro(true);
    MeleeEnemy copy(m);
    EXPECT_EQ(copy.getSprite().getPosition().x, m.getSprite().getPosition().x);
    EXPECT_EQ(copy.getSprite().getPosition().y, m.getSprite().getPosition().y);
    EXPECT_EQ(copy.getStrength(), m.getStrength());
    EXPECT_EQ(false, copy.isParalyzed());
    EXPECT_EQ(copy.isOnFire(), m.isOnFire());
    EXPECT_EQ(copy.getHealth(), m.getHealth());
    EXPECT_EQ(copy.isFacingRight(), m.isFacingRight());
    EXPECT_EQ(copy.getMovementSpeed(), m.getMovementSpeed());
    EXPECT_EQ(false, copy.isAggro());

}