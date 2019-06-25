//
// Created by Pietro on 2019-06-22.
//

#include "gtest/gtest.h"
#include "Knight.h"
#include "defaultValues.h"
#include <SFML/Graphics.hpp>


//Knight(float x, float y, bool onf = false, float h = defHealth, bool facingR = true, float s = HERO_SPEED);

TEST(KnightTest, Constructor) {
    Knight k(5, 0);
    EXPECT_EQ(5, k.getSprite().getPosition().x);
    EXPECT_EQ(0, k.getSprite().getPosition().y);
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(true, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}


TEST(KnightTest, IsOnFire) {
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


TEST(KnightTest, IsFacingLeft) {
    Knight k(0, -5, false, DEF_GAMEHERO_HEALTH, false);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(false, k.isFacingRight());
    EXPECT_EQ(HERO_SPEED, k.getMovementSpeed());
}

TEST(KnightTest, MovementSpeed) {
    Knight k(0, -5, false, DEF_GAMEHERO_HEALTH, false, 10.);
    EXPECT_EQ(0, k.getSprite().getPosition().x);
    EXPECT_EQ(-5, k.getSprite().getPosition().y);
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
    EXPECT_EQ(false, k.isFacingRight());
    EXPECT_EQ(10., k.getMovementSpeed());
}

TEST(KnightTest, Assigment) {
    Knight k(-5, 3, true, 32.15, true, 5.);
    Knight newK = k;
    EXPECT_EQ(newK.getSprite().getPosition().x, k.getSprite().getPosition().x);
    EXPECT_EQ(newK.getSprite().getPosition().y, k.getSprite().getPosition().y);
    EXPECT_EQ(newK.isOnFire(), k.isOnFire());
    EXPECT_EQ(newK.getHealth(), k.getHealth());
    EXPECT_EQ(newK.isFacingRight(), k.isFacingRight());
    EXPECT_EQ(newK.getMovementSpeed(), k.getMovementSpeed());

}

TEST(KnightTest, Copy) {
    Knight k(5, 0, true, 25., false, 0.);
    Knight copy(k);
    EXPECT_EQ(copy.getSprite().getPosition().x, k.getSprite().getPosition().x);
    EXPECT_EQ(copy.getSprite().getPosition().y, k.getSprite().getPosition().y);
    EXPECT_EQ(copy.isOnFire(), k.isOnFire());
    EXPECT_EQ(copy.getHealth(), k.getHealth());
    EXPECT_EQ(copy.isFacingRight(), k.isFacingRight());
    EXPECT_EQ(copy.getMovementSpeed(), k.getMovementSpeed());

}