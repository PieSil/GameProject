//
// Created by Pietro on 2019-06-23.
//

#ifndef GAMEPROJECT_GAMEENTITY_H
#define GAMEPROJECT_GAMEENTITY_H

#include <SFML/Graphics.hpp>
#include "gameValues.h"

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

    const sf::RectangleShape &getHitbox() const {
        return hitbox;
    }

    virtual void move(const Direction &direction, const float &distance, const int &width, const int &height, const float &scale,
         const int &row, const int &lastColumn);

    //virtual void updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn);

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

    sf::Sprite & getSprite() {//non const method allows Game to manage sprite attributes (like position)
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
    void loadTexture(const std::string &path);
    virtual void
    initSprite(const float &x, const float &y, const std::string &path, const int &width, const int &height,
               const float &scale, const int &row, const int &column);
    virtual void giveHitbox(const float &widthReduction, const float &heightReduction, const float &scale);

    //SFML classes are not made for inheritance, preferred aggregation instead
    sf::Texture texture;
    sf::RectangleShape hitbox;
    sf::Text text;
    sf::Sprite sprite;
    float movementSpeed;
    bool facingRight; //boolean value used to determine if the character is facing right or left
    int movingCounter;//counter used to update sprite in order to generate walking/moving animation
};

#endif //GAMEPROJECT_GAMEENTITY_H
