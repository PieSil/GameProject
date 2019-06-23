//
// Created by Pietro on 2019-06-23.
//

#include "GameEntity.h"

GameEntity::GameEntity(sf::Texture t, sf::RectangleShape collR, sf::Text txt) : collisionRect(collR), text(txt) {
    loadTexture("../GameAssets/Sprites/Default_Sprite.png");
}

void GameEntity::loadTexture(const std::string &path) {
    if(!texture.loadFromFile(path)) {
        //exception
    }

    sprite = sf::Sprite(texture);
}
