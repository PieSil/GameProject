//
// Created by Pietro on 2019-06-23.
//

#include "math.h"
#include "GameCharacter.h"
#include "GameEntity.h"
#include "MovingEntity.h"

GameEntity::GameEntity(const float &x, const float &y) : text(std::move(sf::Text())) {

    initSprite(x, y, "../GameAssets/Sprites/Default_Sprite.png", 300, 300, 1, 0, 0);
    giveHitbox(sprite.getPosition(), sprite.getTextureRect().width, sprite.getTextureRect().height, 1, 1, 1);


}

GameEntity::~GameEntity() {}

void GameEntity::loadTexture(const std::string &path) {


    if (!texture.loadFromFile(path)) {
        //exceptiond
    }

    sprite = sf::Sprite(texture);

}

//copy constructor
GameEntity::GameEntity(const GameEntity &copied) : texture(copied.getTexture()), text(copied.getText()),
                                                   sprite(copied.getSprite()), hitbox(copied.getHitbox()) {
}

//default constructor
GameEntity::GameEntity() : GameEntity(0, 0) {

}

void
GameEntity::initSprite(const float &x, const float &y, const std::string &path, const int &width, const int &height,
                       const float &scale, const int &row, const int &column) {

    //loads sprite from GameAssets and sets his origin and position

    loadTexture(path);
    sprite.setTextureRect(sf::IntRect(row, column, width, height));

    //sets origin to center of selected texture Rectangle
    sprite.setOrigin(sprite.getTextureRect().width / 2., sprite.getTextureRect().height / 2.);

    //initializes sprite position
    sprite.setPosition(x, y);

}


/*
void GameEntity::updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) {
}
*/

void
GameEntity::giveHitbox(const sf::Vector2f &position, const int &width, const int &height,
                       const float &widthReduction,
                       const float &heightReduction, const float &scale) {
    hitbox = Hitbox(position, width, height, widthReduction, heightReduction, scale);
}