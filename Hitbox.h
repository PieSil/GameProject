//
// Created by Pietro on 2019-06-27.
//

#ifndef GAMEPROJECT_HITBOX_H
#define GAMEPROJECT_HITBOX_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

class Hitbox {
public:
    Hitbox(const sf::Vector2f &spritePos, const int &width, const float &height, const float &widthReduction,
           const float &heightReduction, const float &scale);

    Hitbox();

    //copy constructor
    Hitbox(const Hitbox& copied);

    void setPosition(const sf::Vector2f& position) {
        hitbox.setPosition(position);
        upperEdge.setPosition(sf::Vector2f(hitbox.getPosition())); //sets upper edge to match with hitbox's upper edge
        lowerEdge.setPosition(sf::Vector2f(hitbox.getPosition().x, (hitbox.getPosition().y + hitbox.getSize().y))); //sets lower edge to match with hitbox's lower edge
        rightEdge.setPosition(sf::Vector2f((hitbox.getPosition().x + hitbox.getSize().x), hitbox.getPosition().y)); //sets right edge to match with hitbox's right edge
        leftEdge.setPosition(sf::Vector2f(hitbox.getPosition())); //sets left edge to match with hitbox's left edge
    }

    void setPosition(const float& x, const float& y) {
        hitbox.setPosition(sf::Vector2f(x,y));
    }

    const sf::Vector2f& getPositionX() {
        return hitbox.getPosition();
    }

    const sf::FloatRect checkHitbox() const {
        return hitbox.getGlobalBounds();
    }

    const sf::FloatRect checkUpperEdge() const {
        return upperEdge.getGlobalBounds();
    }

    const sf::FloatRect checkLowerEdge() const {
        return lowerEdge.getGlobalBounds();
    }

    const sf::FloatRect checkRightEdge() const {
        return rightEdge.getGlobalBounds();
    }

    const sf::FloatRect checkLeftEdge() const {
        return leftEdge.getGlobalBounds();
    }


    const sf::RectangleShape getHitbox() const {
        return hitbox;
    }

    const sf::RectangleShape getUpperEdge() const {
        return upperEdge;
    }

    const sf::RectangleShape getLowerEdge() const {
        return lowerEdge;
    }

    const sf::RectangleShape getRightEdge() const {
        return rightEdge;
    }

    const sf::RectangleShape getLeftEdge() const {
        return leftEdge;
    }

    /*
    const std::list<sf::RectangleShape*> &getAllBoxes() const {
        return allBoxes;
    };
*/

protected:
    void createHitbox(const sf::Vector2f &spritePos, const int &width, const float &height, const float &widthReduction,
                      const float &heightReduction, const float &scale);

    void createEdges(const sf::RectangleShape& hitbox);

    //void fillAllBoxes();

    sf::RectangleShape hitbox;
    sf::RectangleShape upperEdge;
    sf::RectangleShape lowerEdge;
    sf::RectangleShape rightEdge;
    sf::RectangleShape leftEdge;
    //std::list<sf::RectangleShape*> allBoxes; //list filled with hitbox rectangle and edges, used by the window class to draw the complete hitbox
};


#endif //GAMEPROJECT_HITBOX_H
