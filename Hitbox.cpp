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
    upperEdge.setOrigin(hitbox.getOrigin()); //sets origin to match hitbox's origin
    upperEdge.setSize(sf::Vector2f(hitbox.getSize().x, 1)); //same width as hitbox, heght = 1 pixel
    upperEdge.setFillColor(sf::Color::Magenta); //gives color to edge so that it can be seen when drawn

    //create lower edge
    lowerEdge.setOrigin(hitbox.getOrigin()); //sets origin to match hitbox's origin
    lowerEdge.setSize(sf::Vector2f(hitbox.getSize().x, 1)); //same width as hitbox, heght = 1 pixel
    lowerEdge.setFillColor(sf::Color::Magenta); //gives color to edge so that it can be seen when drawn

    //create right edge
    rightEdge.setOrigin(hitbox.getOrigin()); //sets origin to match hitbox's origin
    rightEdge.setSize(sf::Vector2f(1, hitbox.getSize().y)); //same height as hitbox, width = 1 pixel
    rightEdge.setFillColor(sf::Color::Magenta); //gives color to edge so that it can be seen when drawn

    //create left edge
    leftEdge.setOrigin(hitbox.getOrigin()); //sets origin to match hitbox's origin
    leftEdge.setSize(sf::Vector2f(1, hitbox.getSize().y)); //same height as hitbox, width = 1 pixel
    leftEdge.setFillColor(sf::Color::Magenta); //gives color to edge so that it can be seen when drawn
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


