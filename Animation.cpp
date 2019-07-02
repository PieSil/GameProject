//
// Created by Pietro on 2019-07-01.
//

#include "Animation.h"

Animation::Animation(const std::vector<sf::IntRect> &frames, sf::Sprite *sprite, const SpriteParams *parameters,
                     const float &animationTime)
        : frames(frames), sprite(sprite), parameters(parameters), currentFrame(0) {

    frameNumber = -1; //set frame number to -1, this way first frame index is 0

    for (const auto &frame : frames) {
        frameNumber++; //count number of frames
    }

    frameTime = animationTime / frameNumber; //set frameTime based on given animationTime (length in seconds)

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

void Animation::play(const bool &right) {


    //scale sprite to match facing direction:
    if (right) {
        sprite->setScale(parameters->scale, parameters->scale);
    } else {
        sprite->setScale(-parameters->scale, parameters->scale);
    }


    if (elapsed.asSeconds() >= frameTime) {

        sprite->setTextureRect(frames[currentFrame]); //update animation frame

        currentFrame++; //increase currentFrame counter by 1
        if (currentFrame > frameNumber) {
            currentFrame = 0; //reset currentFrame to first frame of frames vector
        }

        elapsed -= sf::seconds(frameTime); //"reset" elapsed time

    }


}



void Animation::checkTime() {

    //this method is made to be called every loop
    //it allows the Animation class to keep track of time even when stored animation is not in use

    if (elapsed.asSeconds() >= frameTime) { //if enough time has passed

        elapsed -= sf::seconds(frameTime); //"reset" elapsed time
    }

    restartClock(); //restart clock
}