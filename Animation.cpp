//
// Created by Pietro on 2019-07-01.
//

#include "Animation.h"

Animation::Animation(const std::vector<sf::IntRect> &frames, sf::Sprite *sprite, const SpriteParams *parameters,
                     const float &animationTime)
        : frames(frames), sprite(sprite), parameters(parameters), currentFrame(0) {

    frameNumber = -1;

    for (const auto &frame : frames) {
        frameNumber++;
    }

    frameTime = animationTime / frameNumber;

}

void Animation::play(const bool &right) {

    if (right) {
        sprite->setScale(parameters->scale, parameters->scale);
    } else {
        sprite->setScale(-parameters->scale, parameters->scale);
    }

    if (elapsed.asSeconds() >= frameTime) {

        sprite->setTextureRect(frames[currentFrame]);

        currentFrame++;
        if (currentFrame > frameNumber) {
            currentFrame = 0;
        }

        elapsed -= sf::seconds(frameTime);

    }

    elapsed += clock.restart();

}

Animation::Animation(const Animation &copied) : Animation(copied.getFrames(), copied.getSprite(),
                                                          copied.getParameters()) {
    frameTime = copied.getFrameTime();
}

Animation &Animation::operator=(const Animation &assigned) {
    frames = assigned.getFrames();
    sprite = assigned.getSprite();
    parameters = assigned.getParameters();
    currentFrame = 0;
    frameNumber = assigned.getFrameNumber();
    frameTime = assigned.getFrameTime();
    elapsed = sf::Time();
    clock = sf::Clock();


    return *this;
}
