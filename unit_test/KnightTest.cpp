//
// Created by Pietro on 2019-06-22.
//

#include "gtest/gtest.h"
#include "Knight.h"
#include "defaultValues.h"
#include <SFML/Graphics.hpp>

TEST(KnightTest, DefaultConstructorTest) {
    Knight k(5, 0);
    EXPECT_EQ(5, k.getPosX());
    EXPECT_EQ(0, k.getPosY());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());
}


TEST(KnightTest, TrueOnFireTest) {
    Knight k(-5, 0, true);
    EXPECT_EQ(-5, k.getPosX());
    EXPECT_EQ(0, k.getPosY());
    EXPECT_EQ(true, k.isOnFire());
    EXPECT_EQ(DEF_GAMEHERO_HEALTH, k.getHealth());

}


TEST(KnightTest, NotDefHealthTest) {
    Knight k(0, -5, false, 540.);
    EXPECT_EQ(0, k.getPosX());
    EXPECT_EQ(-5, k.getPosY());
    EXPECT_EQ(false, k.isOnFire());
    EXPECT_EQ(540., k.getHealth());
}
