//
// Created by Pietro on 2019-06-23.
//

#include "GameEntity.h"

GameEntity::GameEntity(sf::Texture t, sf::RectangleShape collR, sf::Text txt) : collisionRect(collR), text(txt) {
    if (!texture.loadFromFile("../GameAssets/Sprites/Default_Sprite.png")) {
        //exception
    }

    sprite = sf::Sprite(texture);
}
