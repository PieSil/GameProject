//
// Created by Pietro on 2019-06-30.
//

#ifndef GAMEPROJECT_SPRITEOBSERVER_H
#define GAMEPROJECT_SPRITEOBSERVER_H

#include <SFML/Graphics.hpp>

class SpriteObserver {
public:
    virtual void update(const sf::Sprite& sprite) = 0;

protected:
    virtual ~SpriteObserver() = 0;
};


#endif //GAMEPROJECT_SPRITEOBSERVER_H
