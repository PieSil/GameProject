//
// Created by Pietro on 2019-06-22.
//

#include "gtest/gtest.h"
#include "Wizard.h"
#include "defaultValues.h"
#include <SFML/Graphics.hpp>

TEST(WizardTest, DefaultConstructorTest) {
    Wizard w(1,1);
    EXPECT_EQ(1, w.getPosX());
    EXPECT_EQ(1, w.getPosY());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
}

TEST(WizardTest, TrueOnFireTest) {
    Wizard w(1,1, true);
    EXPECT_EQ(1, w.getPosX());
    EXPECT_EQ(1, w.getPosY());
    EXPECT_EQ(true, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(10., w.getMana());
}


TEST(WizardTest, NotDefHealthTest) {
    Wizard w(1,1, false, 34.);
    EXPECT_EQ(1, w.getPosX());
    EXPECT_EQ(1, w.getPosY());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(34., w.getHealth());
    EXPECT_EQ(10., w.getMana());
}


TEST(WizardTest, NotDefManaTest) {
    Wizard w(1,1, false, DEF_GAMEHERO_HEALTH, 3.);
    EXPECT_EQ(1, w.getPosX());
    EXPECT_EQ(1, w.getPosY());
    EXPECT_EQ(false, w.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, w.getHealth());
    EXPECT_EQ(3., w.getMana());
}
