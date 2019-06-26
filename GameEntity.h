//
// Created by Pietro on 2019-06-23.
//

#ifndef GAMEPROJECT_GAMEENTITY_H
#define GAMEPROJECT_GAMEENTITY_H

#include <SFML/Graphics.hpp>

class GameEntity {
public:
    explicit GameEntity(float x, float y, float s = 0., bool facingR = true, sf::Texture t = sf::Texture(),
                        sf::RectangleShape collR = sf::RectangleShape(), sf::Text txt = sf::Text());
    //default constructor
    GameEntity();

    //copy constructor
    GameEntity(const GameEntity &copied);

    virtual ~GameEntity() = 0;

/*
    void updateSprite() {
        sprite.setTexture(texture);
    }
*/

    virtual void updateMovement(int width, int height, float scale, int rowSelector, int lastColumn) = 0;

    virtual void updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn);

    const sf::RectangleShape &getCollisionRect() const {
        return collisionRect;
    }


    const sf::Text &getText() const {
        return text;
    }

    const sf::Texture &getTexture() const {
        return texture;
    }

    const sf::Sprite &getSprite() const {
        return sprite;
    }


    float getMovementSpeed() const {
        return movementSpeed;
    }

    bool isFacingRight() const {
        return facingRight;
    }

    int getMovingCounter() const {
        return movingCounter;
    }


protected:
    virtual void initSprite(float x, float y); //associates sprite to texture, sets its origin and position

    void loadTexture(const std::string &path); //load texture from file and associates it to sprite

    //SFML classes are not made for inheritance, preferred aggregation instead
    sf::Texture texture;
    sf::RectangleShape collisionRect;
    sf::Text text;
    sf::Sprite sprite;
    float movementSpeed;
    bool facingRight; //boolean value used to determine if the character is facing right or left
    int movingCounter;//counter used to update sprite in order to generate walking/moving animation
};

#endif //GAMEPROJECT_GAMEENTITY_H
