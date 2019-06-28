//
// Created by Pietro on 2019-06-22.
//

#include "gtest/gtest.h"
#include "Wizard.h"
#include "gameValues.h"
#include "MovingEntity.h"
#include <SFML/Graphics.hpp>

//Wizard(float x, float y, float str = DEF_GAMEHERO_STRENGTH, bool onf = false, float m = 10., float h = DEF_GAMEHERO_HEALTH, bool facingR = true, float s = HERO_SPEED);


TEST(WizardTest, Constructor) {
    Wizard w(1,1);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().y);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, w.getStrength());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
}

TEST(WizardTest, NotDefStrength) {
    Wizard w(1,1, 3.);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().y);
    EXPECT_EQ(3., w.getStrength());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
}

TEST(WizardTest, NegativeStrength) {
    Wizard w(1,1, -3.);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().y);
    EXPECT_EQ(3., w.getStrength());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
}

TEST(WizardTest, TrueOnFire) {
    Wizard w(1,1, DEF_GAMEHERO_STRENGTH, true);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().y);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, w.getStrength());
    EXPECT_EQ(true, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
}


TEST(WizardTest, NotDefHealth) {
    Wizard w(1,1, DEF_GAMEHERO_STRENGTH, false, 10., 34.);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, w.getStrength());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(34., w.getHealth());
    EXPECT_EQ(10., w.getMana());
}

TEST(WizardTest, NegativeHealth) {
    Wizard w(1,1, DEF_GAMEHERO_STRENGTH, false, 10., -34.);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, w.getStrength());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(34., w.getHealth());
    EXPECT_EQ(10., w.getMana());
}

TEST(WizardTest, NotDefMana) {
    Wizard w(1,1, DEF_GAMEHERO_STRENGTH, false, 3., DEF_GAMEHERO_HEALTH);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, w.getStrength());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(3., w.getMana());
}


TEST(WizardTest, IsFacingLeft) {
    Wizard w(0, -5, DEF_GAMEHERO_STRENGTH, false, 10., DEF_GAMEHERO_HEALTH, false);
    EXPECT_EQ(0, w.getSprite().getPosition().x);
    EXPECT_EQ(-5, w.getSprite().getPosition().y);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, w.getStrength());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
    EXPECT_EQ(false, w.isFacingRight());
    EXPECT_EQ(HERO_SPEED, w.getMovementSpeed());
}

TEST(WizardTest, MovementSpeed) {
    Wizard w(1, -1, DEF_GAMEHERO_STRENGTH, false, 10., DEF_GAMEHERO_HEALTH, true, 35.);
    EXPECT_EQ(1, w.getSprite().getPosition().x);
    EXPECT_EQ(-1, w.getSprite().getPosition().y);
    EXPECT_EQ(DEF_GAMEHERO_STRENGTH, w.getStrength());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
    EXPECT_EQ(true, w.isFacingRight());
    EXPECT_EQ(35., w.getMovementSpeed());
}

TEST(WizardTest, Assigment) {
    Wizard w(1, 1, DEF_GAMEHERO_STRENGTH, true, 10., 23., true, -90.);
    Wizard newW = w;
    EXPECT_EQ(newW.getSprite().getPosition().x, w.getSprite().getPosition().x);
    EXPECT_EQ(newW.getSprite().getPosition().y, w.getSprite().getPosition().y);
    EXPECT_EQ(newW.getStrength(), w.getStrength());
    EXPECT_EQ(newW.isOnFire(), w.isOnFire());
    EXPECT_EQ(newW.getHealth(), w.getHealth());
    EXPECT_EQ(newW.isFacingRight(), w.isFacingRight());
    EXPECT_EQ(newW.getMovementSpeed(), w.getMovementSpeed());

}

TEST(WizardTest, Copy) {
    Wizard w(-1, -1, DEF_GAMEHERO_STRENGTH, false, 8., 10., false, 2.);
    Wizard copy(w);
    EXPECT_EQ(copy.getSprite().getPosition().x, w.getSprite().getPosition().x);
    EXPECT_EQ(copy.getSprite().getPosition().y, w.getSprite().getPosition().y);
    EXPECT_EQ(copy.getStrength(), w.getStrength());
    EXPECT_EQ(copy.isOnFire(), w.isOnFire());
    EXPECT_EQ(copy.getHealth(), w.getHealth());
    EXPECT_EQ(copy.isFacingRight(), w.isFacingRight());
    EXPECT_EQ(copy.getMovementSpeed(), w.getMovementSpeed());
}