//
// Created by Pietro on 2019-06-23.
//

#include "GameEntity.h"

GameEntity::GameEntity(bool facingR, sf::Texture t, sf::RectangleShape collR, sf::Text txt) :
                       facingRight(facingR), collisionRect(collR), text(txt), movingCounter(0) {
    loadTexture("../GameAssets/Sprites/Default_Sprite.png");
}

void GameEntity::loadTexture(const std::string &path) {
    if(!texture.loadFromFile(path)) {
        //exception
    }

    sprite = sf::Sprite(texture);
}
