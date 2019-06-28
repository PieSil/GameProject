//
// Created by Pietro on 2019-06-22.
//

#include "gtest/gtest.h"
#include "Knight.h"
#include "gameValues.h"
#include "MovingEntity.h"
#include <SFML/Graphics.hpp>


//Knight(float x, float y, float str = DEF_GAMEHERO_STRENGTH, bool onf = false, float h = DEF_GAMEHERO_HEALTH, bool facingR = true, float s = HERO_SPEED);

TEST(KnightTest, Constructor) {
    Knight k(5, 0);
    EXPECT_EQ(5, k.getSprite().getPosition().x);
    EXPECT_EQ(0, k.getSprite().getPosition().y);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, k.getStrength());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}

TEST(KnightTest, NotDefStrength) {
    Knight k(5, 0, 25.);
    EXPECT_EQ(5, k.getSprite().getPosition().x);
    EXPECT_EQ(0, k.getSprite().getPosition().y);
    EXPECT_EQ(25., k.getStrength());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}

TEST(KnightTest, NegativeStrength) {
    Knight k(5, 0, -25.);
    EXPECT_EQ(5, k.getSprite().getPosition().x);
    EXPECT_EQ(0, k.getSprite().getPosition().y);
    EXPECT_EQ(25., k.getStrength());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}


TEST(KnightTest, IsOnFire) {
    Knight k(-5, 0, 25., true);
    EXPECT_EQ(-5, k.getSprite().getPosition().x);
    EXPECT_EQ(0, k.getSprite().getPosition().y);
    EXPECT_EQ(25., k.getStrength());
    EXPECT_EQ(true, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());

}


TEST(KnightTest, NotDefHealth) {
    Knight k(0, -5, 2., false, 540.);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(2., k.getStrength());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(540., k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}

TEST(KnightTest, NegativeHealth) {
    Knight k(0, -5, 2., false, -540.);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(2., k.getStrength());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(540., k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}


TEST(KnightTest, IsFacingLeft) {
    Knight k(0, -5, 5.,false, DEF_GAMEHERO_HEALTH, false);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(5., k.getStrength());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(false, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}

TEST(KnightTest, MovementSpeed) {
    Knight k(0, -5, DEF_GAMEHERO_STRENGTH, false, DEF_GAMEHERO_HEALTH, false, 10.);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, k.getStrength());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(false, k.isFacingRight());
    EXPECT_EQ(10., k.getMovementSpeed());
}

TEST(KnightTest, Assigment) {
    Knight k(-5, 3, DEF_GAMEHERO_STRENGTH, true, 32.15, true, 5.);
    Knight newK = k;
    EXPECT_EQ(newK.getSprite().getPosition().x, k.getSprite().getPosition().x);
    EXPECT_EQ(newK.getSprite().getPosition().y, k.getSprite().getPosition().y);
    EXPECT_EQ(newK.getStrength(), k.getStrength());
    EXPECT_EQ(newK.isOnFire(), k.isOnFire());
    EXPECT_EQ(newK.getHealth(), k.getHealth());
    EXPECT_EQ(newK.isFacingRight(), k.isFacingRight());
    EXPECT_EQ(newK.getMovementSpeed(), k.getMovementSpeed());

}

TEST(KnightTest, Copy) {
    Knight k(5, 0, DEF_GAMEHERO_STRENGTH, true, 25., false, 0.);
    Knight copy(k);
    EXPECT_EQ(copy.getSprite().getPosition().x, k.getSprite().getPosition().x);
    EXPECT_EQ(copy.getSprite().getPosition().y, k.getSprite().getPosition().y);
    EXPECT_EQ(copy.getStrength(), k.getStrength());
    EXPECT_EQ(copy.isOnFire(), k.isOnFire());
    EXPECT_EQ(copy.getHealth(), k.getHealth());
    EXPECT_EQ(copy.isFacingRight(), k.isFacingRight());
    EXPECT_EQ(copy.getMovementSpeed(), k.getMovementSpeed());

}