//
// Created by Pietro on 2019-06-23.
//

#include "GameEntity.h"

GameEntity::GameEntity(const float &x, const float &y, const float &s, const bool &facingR,sf::Texture t,
                       sf::RectangleShape collR, sf::Text txt) :
                       movementSpeed(s), facingRight(facingR), hitbox(std::move(collR)), text(std::move(txt)), movingCounter(0) {
    initSprite(x,y);
    giveHitbox(1, 1, 1);
}

GameEntity::~GameEntity() {}

void GameEntity::loadTexture(const std::string &path) {
    if(!texture.loadFromFile(path)) {
        //exceptiond
    }
    sprite = sf::Sprite(texture);
}

//copy constructor
GameEntity::GameEntity(GameEntity &copied) : movingCounter(0), movementSpeed(copied.getMovementSpeed()), facingRight(copied.isFacingRight()) {
    texture = sf::Texture(copied.getTexture());
    sprite = sf::Sprite(copied.getSprite());
    hitbox = sf::RectangleShape(copied.getHitbox());
    text = sf::Text(copied.getText());
}

//default constructor
GameEntity::GameEntity() : GameEntity(0,0) {

}

void GameEntity::initSprite(float x, float y) {
    //loads sprite from GameAssets and sets his origin and position
    loadTexture("../GameAssets/Sprites/Default_Sprite.png");

    //set sprite origin to match texture center
    sprite.setOrigin(sprite.getTexture()->getSize().x/2., sprite.getTexture()->getSize().y/2.);

    //initializes sprite position
    sprite.setPosition(x,y);
}

void GameEntity::move(const Direction &direction, const float &distance, const int &width, const int &height,
                      const float &scale, const int &row, const int &lastColumn) {
    if (direction == RIGHT) {

        sprite.move(distance, 0.); //move right


        sprite.setTextureRect(sf::IntRect(width * movingCounter, width * row, width, height)); //update sprite animation


        if (!(facingRight)) { //flip horizontally
            sprite.setScale(scale * 1.f, scale * 1.f);
            facingRight = true;
        }

    } else if (direction == LEFT) {

        sprite.move(-distance, 0.); //move left


        sprite.setTextureRect(sf::IntRect(width * movingCounter, width * row, width, height)); //update sprite animation


        if (facingRight) { //flip horizontally
            sprite.setScale(-(scale * 1.f), scale * 1.f);
            facingRight = false;
        }
    } else {
        //TODO: throw exception
    }

    //moves hitbox with sprite
    hitbox.setPosition(sprite.getPosition());

    //update movingCounter
    movingCounter++;

    if (movingCounter > lastColumn) {
        movingCounter = 0;
    }
}

void GameEntity::giveHitbox(const float &widthReduction, const float &heightReduction, const float &scale) {
    //set origin size and position to match the sprite
    hitbox.setSize(sf::Vector2f(scale * sprite.getTextureRect().width/widthReduction, scale * sprite.getTextureRect().height/heightReduction));
    hitbox.setOrigin(hitbox.getSize().x/2, hitbox.getSize().y/2);
    hitbox.setPosition(sprite.getPosition());

    //set color to white to see hitbox when displayed
    hitbox.setFillColor(sf::Color::White);
}
/*
void GameEntity::updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) {
}
*/

