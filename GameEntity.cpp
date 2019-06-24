//
// Created by Pietro on 2019-06-23.
//

#include "GameEntity.h"

GameEntity::GameEntity(float x, float y, float s, bool facingR, sf::Texture t, sf::RectangleShape collR, sf::Text txt) :
                       movementSpeed(s), facingRight(facingR), collisionRect(collR), text(txt), movingCounter(0) {
    loadTexture("../GameAssets/Sprites/Default_Sprite.png");
    //set sprite origin to match texture center
    sprite.setOrigin(sprite.getTexture()->getSize().x/2., sprite.getTexture()->getSize().y/2.);
    //initializes sprite position
    sprite.setPosition(x,y);
}

GameEntity::~GameEntity() {}

void GameEntity::loadTexture(const std::string &path) {
    if(!texture.loadFromFile(path)) {
        //exceptiond
    }
    sprite = sf::Sprite(texture);
}
