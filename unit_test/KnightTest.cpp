//
// Created by Pietro on 2019-06-22.
//

#include "gtest/gtest.h"
#include "Knight.h"
#include "defaultValues.h"
#include <SFML/Graphics.hpp>


//Knight(float x, float y, bool onf = false, float h = defHealth, bool facingR = true, float s = HERO_SPEED);

TEST(KnightTest, DefaultConstructor) {
    Knight k(5, 0);
    EXPECT_EQ(5, k.getSprite().getPosition().x);
    EXPECT_EQ(0, k.getSprite().getPosition().y);
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}


TEST(KnightTest, isOnFire) {
    Knight k(-5, 0, true);
    EXPECT_EQ(-5, k.getSprite().getPosition().x);
    EXPECT_EQ(0, k.getSprite().getPosition().y);
    EXPECT_EQ(true, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());

}


TEST(KnightTest, NotDefHealth) {
    Knight k(0, -5, false, 540.);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(540., k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}


TEST(KnightTest, isFacingLeft) {
    Knight k(0, -5, false, DEF_GAMEHERO_HEALTH, false);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(false, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}

TEST(KnightTest, movementSpeed) {
    Knight k(0, -5, false, DEF_GAMEHERO_HEALTH, false, 10.);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(false, k.isFacingRight());
    EXPECT_EQ(10., k.getMovementSpeed());
}