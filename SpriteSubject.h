//
// Created by Pietro on 2019-06-30.
//

#ifndef GAMEPROJECT_SPRITESUBJECT_H
#define GAMEPROJECT_SPRITESUBJECT_H

#include "SpriteObserver.h"

class SpriteSubject {
public:

    virtual void registerObserver(SpriteObserver* observer) = 0;

    virtual void removeObserver(SpriteObserver* observer) = 0;

    virtual void notifyObservers();

protected:

    virtual ~SpriteSubject() = 0;

};


#endif //GAMEPROJECT_SPRITESUBJECT_H
