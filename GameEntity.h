//
// Created by Pietro on 2019-06-23.
//

#ifndef GAMEPROJECT_GAMEENTITY_H
#define GAMEPROJECT_GAMEENTITY_H

#include <SFML/Graphics.hpp>
#include "gameValues.h"
#include "Hitbox.h"

class GameEntity {
public:
    explicit GameEntity(const float &x, const float &y, const float &s = 0., const bool &facingR = true,
                        sf::Texture t = sf::Texture(), sf::Text txt = sf::Text());

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

    const Hitbox &getHitbox() const {
        return hitbox;
    }

    virtual void
    moveOnX(const Direction &direction, const float &distance, const int &width, const int &height, const float &scale,
            const int &row, const int &lastColumn);


    virtual void moveOnY(const float &height, const Direction &direction);


    const sf::Text &getText() const {
        return text;
    }

    const sf::Texture &getTexture() const {
        return texture;
    }

    void setTexture(const sf::Texture &texture) {
        //updateSprite();
        GameEntity::texture = texture;
    }

    sf::Sprite &getSprite() {//non const method allows Game to manage sprite attributes (like position)
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


    bool isOnGround() const {
        return onGround;
    }

    void setOnGround(bool onGround) {
        GameEntity::onGround = onGround;
    }

    float getVelocityY() const {
        return velocityY;
    }

    void setVelocityY(float velocityY) {
        GameEntity::velocityY = velocityY;
    }

protected:
    void loadTexture(const std::string &path);

    virtual void
    initSprite(const float &x, const float &y, const std::string &path, const int &width, const int &height,
               const float &scale, const int &row, const int &column);

    virtual void
    giveHitbox(const sf::Vector2f &position, const int &width, const int &height, const float &widthReduction,
               const float &heightReduction, const float &scale);

    //SFML classes are not made for inheritance, preferred aggregation instead
    sf::Texture texture;
    sf::Text text;
    sf::Sprite sprite;

    Hitbox hitbox;
    float movementSpeed;
    bool facingRight; //boolean value used to determine if the character is facing right or left
    float movingCounter;//counter used to update sprite in order to generate walking/moving animation

//used for jumping and falling
    bool onGround;
    float velocityY;
};

#endif //GAMEPROJECT_GAMEENTITY_H
