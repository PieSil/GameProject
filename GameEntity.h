//
// Created by Pietro on 2019-06-23.
//

#ifndef GAMEPROJECT_GAMEENTITY_H
#define GAMEPROJECT_GAMEENTITY_H

#include <queue>
#include <SFML/Graphics.hpp>


class GameEntity {
public:
    explicit GameEntity(sf::Texture t = sf::Texture(), sf::RectangleShape collR = sf::RectangleShape(), sf::Text txt = sf::Text());


    void updateSprite() {
        sprite.setTexture(texture);
    }

    const sf::RectangleShape &getCollisionRect() const {
        return collisionRect;
    }

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

protected:
    sf::Texture texture;
    sf::RectangleShape collisionRect;
    sf::Text text;
    sf::Sprite sprite;
};


#endif //GAMEPROJECT_GAMEENTITY_H
