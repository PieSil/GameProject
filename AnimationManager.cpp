//
// Created by Pietro on 2019-07-01.
//

#include "AnimationManager.h"

AnimationManager::AnimationManager(sf::Sprite *sprite, const SpriteParams *parameters) : parameters(parameters),
                                                                                         sprite(sprite) {


}

void AnimationManager::createAnimation(const State &state) {

    std::vector<sf::IntRect> framesVector;

    switch (state) {
        case IDLE:


            for (auto col = 0; col <= parameters->idleLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->idleRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(IDLE, Animation(framesVector, sprite, parameters, IDLE_ANIM_TIME));
            break;

        case WALKING:

            for (auto col = 0; col <= parameters->movLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->movRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(WALKING, Animation(framesVector, sprite, parameters, WALK_ANIM_TIME));
            break;

        case ATTACKING:
            for (auto col = 0; col <= parameters->attLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * (parameters->width + parameters->attOffset), parameters->attRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(ATTACKING, Animation(framesVector, sprite, parameters, ATT_ANIM_TIME));
            break;

        case SHOOTING:
            for (auto col = 0; col <= parameters->shootLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->shootRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(SHOOTING, Animation(framesVector, sprite, parameters, SHOOT_ANIM_TIME));
            break;


        default:
            //TODO throw exception? just add another idle animation for now
            for (auto col = 0; col <= parameters->idleLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->idleRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(IDLE, Animation(framesVector, sprite, parameters, IDLE_ANIM_TIME));
            break;
    }

}

void AnimationManager::play(const State &state, const bool &right) {
    animations.find(state)->second.play(right); //find selected animation and play it

    for (auto& animation : animations) {
        animation.second.checkTime(); //check weather elapsed attribute should be reset or not and restart the clock, do this for every animation
    }
}

AnimationManager::AnimationManager(const AnimationManager &copied) : AnimationManager(copied.getSprite(),
                                                                                      copied.getParameters()) {
    animations = copied.getAnimations();
}

AnimationManager &AnimationManager::operator=(const AnimationManager &assigned) {
    animations = assigned.getAnimations();
    parameters = assigned.getParameters();
    sprite = assigned.getSprite();
    return *this;
}
