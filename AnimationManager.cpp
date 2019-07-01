//
// Created by Pietro on 2019-07-01.
//

#include "AnimationManager.h"

AnimationManager::AnimationManager(sf::Sprite *sprite, const SpriteParams *parameters) : parameters(parameters), sprite(sprite) {



}

void AnimationManager::createAnimation(const std::string& animationType) {

    if (animationType == "idle") {
        std::vector<sf::IntRect> idle;

        for (auto col = 0; col <= parameters->idleLastCol; col++) {
            idle.emplace_back(sf::IntRect(col * parameters->width, parameters->idleRow * parameters->height, parameters->width, parameters->height));
        }

        animations.emplace("idle", Animation(idle, sprite, parameters, IDLE_ANIM_TIME));

    } else if (animationType == "walking") {
        std::vector<sf::IntRect> walking;

        for (auto col = 0; col <= parameters->movLastCol; col++) {
            walking.emplace_back(sf::IntRect(col * parameters->width, parameters->movRow * parameters->height, parameters->width, parameters->height));
        }

        animations.emplace("walking", Animation(walking, sprite, parameters, WALK_ANIM_TIME));
    }

}

void AnimationManager::play(const std::string &animationType, const bool &right) {
    auto itr = animations.find(animationType);
    itr->second.play(right);
}

AnimationManager::AnimationManager(const AnimationManager &copied) : AnimationManager(copied.getSprite(), copied.getParameters()) {
    animations = copied.getAnimations();
}

AnimationManager& AnimationManager::operator=(const AnimationManager& assigned) {
    animations = assigned.getAnimations();
    parameters = assigned.getParameters();
    sprite = assigned.getSprite();
    return *this;
}
