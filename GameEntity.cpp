//
// Created by Pietro on 2019-06-23.
//

#include "math.h"
#include "GameCharacter.h"
#include "GameEntity.h"
#include "MovingEntity.h"

const SpriteParams GameEntity::entityParams(300, 300, 1, 1, 0.75, "../GameAssets/Sprites/Default_Sprite.png", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

GameEntity::GameEntity(const float &x, const float &y) : text(std::move(sf::Text())), idleCounter(0), animManager(&sprite, getParameters()), state(EntityState::IDLE) {

    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());

}

GameEntity::~GameEntity() {}

void GameEntity::loadTexture(const std::string &path) {


    if (!texture.loadFromFile(path)) {
        //TODO: exception?
    }

    sprite = sf::Sprite(texture);

}

//copy constructor
GameEntity::GameEntity(const GameEntity &copied) : texture(copied.getTexture()), text(copied.getText()),
                                                   sprite(copied.getSprite()), hitbox(copied.getHitbox()), idleCounter(0), animManager(copied.getAnimManager()) {
}

//default constructor
GameEntity::GameEntity() : GameEntity(0, 0) {

}

void
GameEntity::initSprite(const float &x, const float &y) {

    //loads sprite from GameAssets and sets its origin and position
    loadTexture(getParameters()->path);
    sprite.setTextureRect(sf::IntRect(0, getParameters()->idleRow, getParameters()->width, getParameters()->height));

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
GameEntity::giveHitbox() {
    hitbox = Hitbox(sprite.getPosition(), sprite.getTextureRect().width, sprite.getTextureRect().height,
                    getParameters()->widthRed, getParameters()->heightRed, getParameters()->scale);
}

void GameEntity::setupAnimations(const SpriteParams *parameters) {
    animManager = AnimationManager(&sprite, parameters); //create animation sprite
    animManager.createAnimation(EntityState::IDLE); //create idle animation
}

void GameEntity::animate() {
    animManager.play(state, true); //play animation based on entity state
}