//
// Created by Pietro on 2019-06-23.
//

#ifndef GAMEPROJECT_GAMEENTITY_H
#define GAMEPROJECT_GAMEENTITY_H

#include <SFML/Graphics.hpp>
#include "Hitbox.h"
#include "SpriteParameters.h"
#include "AnimationManager.h"
#include "AttackBehaviour.h"
#include "MeleeBehaviour.h"
#include "ShootingBehaviour.h"
#include "AudioPlayer.h"

class GameEntity {
public:
    explicit GameEntity(const float &x, const float &y);

    //default constructor
    GameEntity();

    //copy constructor
    GameEntity(const GameEntity &copied);

    virtual ~GameEntity() = 0;

    virtual void setupAnimations(const SpriteParams *parameters);

    virtual void animate();

    void setupAudio() {}

    virtual const SpriteParams* getParameters() const {
        return &entityParams;
    }

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
        GameEntity::texture = texture;
    }

    const sf::Sprite &getSprite() const {
        return sprite;
    }

    const AnimationManager &getAnimManager() const {
        return animManager;
    }

    EntityState getState() const {
        return state;
    }

    void setState(EntityState state) {
        GameEntity::state = state;
    }

protected:
    void loadTexture(const std::string &path);

    virtual void
    initSprite(const float &x, const float &y);

    virtual void
    giveHitbox();

    //SFML classes are not made for inheritance, preferred aggregation instead
    sf::Texture texture;
    sf::Text text;
    sf::Sprite sprite;
    Hitbox hitbox;

    EntityState state;

    float idleCounter;

    static const SpriteParams entityParams;

    AnimationManager animManager;

    AudioPlayer audioPlayer;
};

#endif //GAMEPROJECT_GAMEENTITY_H
