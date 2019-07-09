//
// Created by Pietro on 2019-07-06.
//

#include "gtest/gtest.h"
#include "Hitbox.h"

TEST(HitboxTest, Initialization) {
    Hitbox h(sf::Vector2f(5, 5), 10, 10, 1, 1, 1);
    EXPECT_EQ(0, h.getLeftEdge().getPosition().x);
    EXPECT_EQ(10, h.getRightEdge().getPosition().x);
    EXPECT_EQ(0, h.getUpperEdge().getPosition().y);
    EXPECT_EQ(10, h.getLowerEdge().getPosition().y);
}