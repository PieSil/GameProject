//
// Created by Pietro on 2019-07-01.
//

#ifndef GAMEPROJECT_ANIMATIONMANAGER_H
#define GAMEPROJECT_ANIMATIONMANAGER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "spriteParameters.h"
#include <map>
#include <iostream>

class AnimationManager {
public:
    AnimationManager(sf::Sprite *sprite, const SpriteParams *parameters);

    AnimationManager(const AnimationManager& copied);

    AnimationManager& operator = (const AnimationManager& assigned);

    ~AnimationManager() {};

    void play(const State &state, const bool &right);

    void resetAnimation(const State& state) {
        animations.find(state)->second.setCurrentFrame(0);
    };

    void createAnimation(const State &state);

    int getCurrentFrame(const State& state) const {
        return animations.find(state)->second.getCurrentFrame();
    }

    const std::map<State, Animation> &getAnimations() const {
        return animations;
    }

    const SpriteParams *getParameters() const {
        return parameters;
    }

    sf::Sprite *getSprite() const {
        return sprite;
    }

protected:
    std::map<State, Animation> animations;
    const SpriteParams* parameters;
    sf::Sprite* sprite;
};


#endif //GAMEPROJECT_ANIMATIONMANAGER_H
