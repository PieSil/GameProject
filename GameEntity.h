//
// Created by Pietro on 2019-06-23.
//

#ifndef GAMEPROJECT_GAMEENTITY_H
#define GAMEPROJECT_GAMEENTITY_H

#include <SFML/Graphics.hpp>
#include "defaultValues.h"

class GameEntity {
public:
    explicit GameEntity(const float& x, const float& y, const float& s = 0., const bool& facingR = true, sf::Texture t = sf::Texture(),
                        sf::RectangleShape collR = sf::RectangleShape(), sf::Text txt = sf::Text());
    //default constructor
    GameEntity();

    //copy constructor
    GameEntity(GameEntity &copied);

    virtual ~GameEntity() = 0;

/*
    void updateSprite() {
        sprite.setTexture(texture);
    }
*/
    void loadTexture(const std::string &path);

    const sf::RectangleShape &getCollisionRect() const {
        return collisionRect;
    }

    virtual void move(const Direction &direction, const float &distance, const int &width, const int &height, const float &scale,
         const int &row, const int &lastColumn);

    //virtual void updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn);

    virtual void initSprite(float x, float y);

    void setCollisionRect(const sf::RectangleShape &collisionRect) {
        GameEntity::collisionRect = collisionRect;
    }

    const sf::Text &getText() const {
        return text;
    }

    void setText(const sf::Text &text) {
        GameEntity::text = text;
    }

    const sf::Texture &getTexture() const {
        return texture;
    }

    void setTexture(const sf::Texture &texture) {
        //updateSprite();
        GameEntity::texture = texture;
    }

    sf::Sprite & getSprite() {//non const method allows Game to manage sprite attributes (like position)
        return sprite;
    }

    void setSprite(const sf::Sprite &sprite) {
        GameEntity::sprite = sprite;
    }

    void setOrigin(const float &x, const float &y) {
        sprite.setOrigin(x,y);
    }

    void setPosition(const float &x, const float &y) {
        sprite.setPosition(x,y);
    }


    float getMovementSpeed() const {
        return movementSpeed;
    }

    void setMovementSpeed(float movementSpeed) {
        GameEntity::movementSpeed = movementSpeed;
    }

    bool isFacingRight() const {
        return facingRight;
    }

    void setFacingRight(bool facingRight) {
        GameEntity::facingRight = facingRight;
    }

    int getMovingCounter() const {
        return movingCounter;
    }

    void setMovingCounter(int movingCounter) {
        GameEntity::movingCounter = movingCounter;
    }


protected:

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
