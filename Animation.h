//
// Created by Pietro on 2019-07-01.
//

#ifndef GAMEPROJECT_ANIMATION_H
#define GAMEPROJECT_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "gameValues.h"
#include "spriteParameters.h"


class Animation {
public:
    Animation(const std::vector<sf::IntRect> &frames, sf::Sprite *sprite, const SpriteParams *parameters,
              const float &animationTime = 1.);

    Animation(const Animation& copied);

    ~Animation() {};

    Animation& operator=(const Animation& assigned);

    void play(const bool &right);

    void checkTime();

    void restartClock() {
        elapsed += clock.restart();
    }

    const std::vector<sf::IntRect> &getFrames() const {
        return frames;
    }

    sf::Sprite *getSprite() const {
        return sprite;
    }

    const SpriteParams *getParameters() const {
        return parameters;
    }

    int getCurrentFrame() const {
        return currentFrame;
    }

    void setCurrentFrame(int currentFrame) {
        Animation::currentFrame = currentFrame;
    }

    int getFrameNumber() const {
        return frameNumber;
    }


    float getFrameTime() const {
        return frameTime;
    }

protected:
    std::vector<sf::IntRect> frames;
    sf::Sprite *sprite;
   const SpriteParams* parameters;

    int currentFrame;
    int frameNumber;

    sf::Clock clock;
    sf::Time elapsed;
    float frameTime;

};


#endif //GAMEPROJECT_ANIMATION_H
