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
    explicit GameEntity(const float &x, const float &y);

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

    const Hitbox &getHitbox() const {
        return hitbox;
    }


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

    const sf::Sprite &getSprite() const {
        return sprite;
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

};

#endif //GAMEPROJECT_GAMEENTITY_H
