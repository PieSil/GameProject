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
    virtual ~GameEntity() = 0;


    void updateSprite() {
        sprite.setTexture(texture);
    }

    void loadTexture(const std::string &path);

    const sf::RectangleShape &getCollisionRect() const {
        return collisionRect;
    }

    virtual void updateMovement(int width, int height, float scale, int rowSelector, int lastColumn) = 0;

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
        updateSprite();
        GameEntity::texture = texture;
    }

    const sf::Sprite &getSprite() const {
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
