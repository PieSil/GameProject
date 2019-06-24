//
// Created by Pietro on 2019-06-22.
//

#include "gtest/gtest.h"
#include "Wizard.h"
#include "defaultValues.h"
#include <SFML/Graphics.hpp>

//Wizard(float x, float y, bool onf = false, float m = 10., float h = defHealth, bool facingR = true, float s = HERO_SPEED);

TEST(WizardTest, DefaultConstructorTest) {
    Wizard w(1,1);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().y);
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
}

TEST(WizardTest, TrueOnFireTest) {
    Wizard w(1,1, true);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().y);
    EXPECT_EQ(true, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
}


TEST(WizardTest, NotDefHealthTest) {
    Wizard w(1,1, false, 10., 34.);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(34., w.getHealth());
    EXPECT_EQ(10., w.getMana());
}


TEST(WizardTest, NotDefManaTest) {
    Wizard w(1,1, false, 3., DEF_GAMEHERO_HEALTH);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(3., w.getMana());
}


TEST(WizardTest, isFacingLeft) {
    Wizard w(0, -5, false, 10., DEF_GAMEHERO_HEALTH, false);
    EXPECT_EQ(0, w.getSprite().getPosition().x);
    EXPECT_EQ(-5, w.getSprite().getPosition().y);
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
    EXPECT_EQ(false, w.isFacingRight());
    EXPECT_EQ(HERO_SPEED, w.getMovementSpeed());
}

TEST(WizardTest, movementSpeed) {
    Wizard w(1, -1, false, 10., DEF_GAMEHERO_HEALTH, true, 35.);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(-1, w.getSprite().getPosition().y);
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
    EXPECT_EQ(true, w.isFacingRight());
    EXPECT_EQ(35., w.getMovementSpeed());
}