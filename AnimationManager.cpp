//
// Created by Pietro on 2019-07-01.
//

#include "AnimationManager.h"

AnimationManager::AnimationManager(sf::Sprite *sprite, const SpriteParams *parameters) : parameters(parameters),
                                                                                         sprite(sprite) {


}

void AnimationManager::createAnimation(const EntityState &state) {

    std::vector<sf::IntRect> framesVector;

    switch (state) {
        case EntityState::IDLE:


            for (auto col = 0; col <= parameters->idleLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->idleRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(EntityState::IDLE, Animation(framesVector, sprite, parameters, IDLE_ANIM_TIME));
            break;

        case EntityState::WALKING:

            for (auto col = 0; col <= parameters->movLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->movRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(EntityState::WALKING, Animation(framesVector, sprite, parameters, WALK_ANIM_TIME));
            break;

        case EntityState::MELEE :
            for (auto col = 0; col <= parameters->attLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * (parameters->width + parameters->attOffset), parameters->attRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(EntityState::MELEE, Animation(framesVector, sprite, parameters, ATT_ANIM_TIME));
            break;

        case EntityState::SHOOTING:
            for (auto col = 0; col <= parameters->shootLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->shootRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(EntityState::SHOOTING, Animation(framesVector, sprite, parameters, SHOOT_ANIM_TIME));
            break;

        case EntityState::DYING :
            for (auto col = 0; col <= parameters->deathLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->deathRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(EntityState::DYING, Animation(framesVector, sprite, parameters, DEATH_ANIM_TIME));
            break;

        case EntityState::DEAD :

            //keep character on last frame of death animation
            for (auto col = parameters->deathLastCol; col <= parameters->deathLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->deathRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(EntityState::DEAD, Animation(framesVector, sprite, parameters, DEATH_ANIM_TIME));
            break;


        default:
            //TODO throw exception? just add another idle animation for now
            for (auto col = 0; col <= parameters->idleLastCol; col++) {
                framesVector.emplace_back(
                        sf::IntRect(col * parameters->width, parameters->idleRow * parameters->height,
                                    parameters->width, parameters->height));
            }

            animations.emplace(EntityState::IDLE, Animation(framesVector, sprite, parameters, IDLE_ANIM_TIME));
            break;
    }

}

void AnimationManager::play(const EntityState &state, const bool &right) {
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
