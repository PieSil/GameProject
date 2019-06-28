//
// Created by Pietro on 2019-06-23.
//

#include "GameEntity.h"

GameEntity::GameEntity(const float &x, const float &y, const float &s, const bool &facingR, sf::Texture t, sf::Text txt) :
                       movementSpeed(s), facingRight(facingR), text(std::move(txt)), movingCounter(0) {
    initSprite(x, y, "../GameAssets/Sprites/Default_Sprite.png", 300, 300, 1, 0, 0);
    giveHitbox(sprite.getPosition(), sprite.getTextureRect().width, sprite.getTextureRect().height, 1, 1, 1);
}

GameEntity::~GameEntity() {}

void GameEntity::loadTexture(const std::string &path) {
    if(!texture.loadFromFile(path)) {
        //exceptiond
    }
    sprite = sf::Sprite(texture);
}

//copy constructor
GameEntity::GameEntity(GameEntity &copied) : texture(copied.getTexture()), text(copied.getText()), sprite(copied.getSprite()), hitbox(copied.getHitbox()), movingCounter(0), movementSpeed(copied.getMovementSpeed()), facingRight(copied.isFacingRight()) {
}

//default constructor
GameEntity::GameEntity() : GameEntity(0, 0, 100, true, sf::Texture(), sf::Text()) {

}

void
GameEntity::initSprite(const float &x, const float &y, const std::string &path, const int &width, const int &height,
                       const float &scale, const int &row, const int &column) {
    //loads sprite from GameAssets and sets his origin and position

    loadTexture(path);
    sprite.setTextureRect(sf::IntRect(row,column,width,height));

    //sets origin to center of selected texture Rectangle
    sprite.setOrigin(sprite.getTextureRect().width/2., sprite.getTextureRect().height/2.);

    //initializes sprite position
    sprite.setPosition(x,y);
    if (facingRight) {
        sprite.setScale(scale*1.f,scale*1.f);
    } else {
        sprite.setScale(-scale*1.f,scale*1.f);
    }
}

void GameEntity::move(const Direction &direction, const float &distance, const int &width, const int &height,
                      const float &scale, const int &row, const int &lastColumn) {
    if (direction == RIGHT) {

        sprite.move(distance, 0.); //move right


        sprite.setTextureRect(sf::IntRect(width * static_cast<int>(movingCounter), width * row, width, height)); //update sprite animation


        if (!(facingRight)) { //flip horizontally
            sprite.setScale(scale * 1.f, scale * 1.f);
            facingRight = true;
        }

    } else if (direction == LEFT) {

        sprite.move(-distance, 0.); //move left


        sprite.setTextureRect(sf::IntRect(width * static_cast<int>(movingCounter), width * row, width, height)); //update sprite animation


        if (facingRight) { //flip horizontally
            sprite.setScale(-(scale * 1.f), scale * 1.f);
            facingRight = false;
        }

        } else if (direction == UP) {

            sprite.move(0, -distance);

        } else if (direction == DOWN) {

            sprite.move(0, distance);

        } else {
        //TODO: throw exception
    }

    //moves hitbox with sprite
    hitbox.setPosition(sprite.getPosition());

    //update movingCounter
    movingCounter += 0.5;

    if (movingCounter > lastColumn) {
        movingCounter = 0;
    }
}

void
GameEntity::giveHitbox(const sf::Vector2f &position, const int &width, const int &height, const float &widthReduction,
                       const float &heightReduction, const float &scale) {
    hitbox = Hitbox(position, width,height, widthReduction, heightReduction, scale);
}
/*
void GameEntity::updateBehaviour(int width, int height, float scale, int rowSelector, int lastColumn) {
}
*/

