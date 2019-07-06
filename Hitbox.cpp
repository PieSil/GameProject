//
// Created by Pietro on 2019-06-27.
//

#include "Hitbox.h"

Hitbox::Hitbox(const sf::Vector2f &spritePos, const int &width, const float &height, const float &widthReduction,
               const float &heightReduction, const float &scale) {
    createHitbox(spritePos, width, height, widthReduction, heightReduction, scale);
    //fillAllBoxes();
}

void
Hitbox::createHitbox(const sf::Vector2f &spritePos, const int &width, const float &height, const float &widthReduction,
                     const float &heightReduction, const float &scale) {
    //set origin size and position to match the sprite
    hitbox.setSize(sf::Vector2f(scale * width / widthReduction, scale * height / heightReduction));
    hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y / 2);
    createEdges(hitbox);
    setPosition(spritePos);

    //set color to white to see hitbox when displayed
    hitbox.setFillColor(sf::Color::White);

}

void Hitbox::createEdges(const sf::RectangleShape& hitbox) {
    //create upper edge
    upperEdge.setSize(sf::Vector2f(hitbox.getSize().x, EDGE_THICKNESS)); //same width as hitbox, heght = 1 pixel
    upperEdge.setOrigin(upperEdge.getSize().x/2., upperEdge.getSize().y/2.);
    upperEdge.setFillColor(sf::Color::Magenta); //gives color to edge so that it can be seen when drawn

    //create lower edge
    lowerEdge.setSize(sf::Vector2f(hitbox.getSize().x, EDGE_THICKNESS)); //same width as hitbox, heght = 1 pixel
    lowerEdge.setOrigin(lowerEdge.getSize().x/2., lowerEdge.getSize().y/2.);
    lowerEdge.setFillColor(sf::Color::Cyan); //gives color to edge so that it can be seen when drawn

    //create right edge
    rightEdge.setSize(sf::Vector2f(EDGE_THICKNESS, hitbox.getSize().y)); //same height as hitbox, width = 1 pixel
    rightEdge.setOrigin(rightEdge.getSize().x/2., rightEdge.getSize().y/2.);
    rightEdge.setFillColor(sf::Color::Green); //gives color to edge so that it can be seen when drawn

    //create left edge
    leftEdge.setSize(sf::Vector2f(EDGE_THICKNESS, hitbox.getSize().y)); //same height as hitbox, width = 1 pixel
    leftEdge.setOrigin(leftEdge.getSize().x/2., leftEdge.getSize().y/2.);
    leftEdge.setFillColor(sf::Color::Yellow); //gives color to edge so that it can be seen when drawn
}

Hitbox::Hitbox(const Hitbox &copied) : hitbox(copied.getHitbox()), upperEdge(copied.getUpperEdge()),
lowerEdge(copied.getLowerEdge()), rightEdge(copied.getRightEdge()), leftEdge(copied.getLeftEdge()) {

}

/*
void Hitbox::fillAllBoxes() {

    //pushes hitbox rectangle and edges in a list
    allBoxes.push_back(&hitbox);
    allBoxes.push_back(&upperEdge);
    allBoxes.push_back(&lowerEdge);
    allBoxes.push_back(&rightEdge);
    allBoxes.push_back(&leftEdge);
}
 */

Hitbox::Hitbox() : Hitbox(sf::Vector2f(0,0), 10, 10, 1, 1, 1) {

}


