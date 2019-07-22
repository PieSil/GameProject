//
// Created by Pietro on 2019-07-20.
//

#ifndef GAMEPROJECT_SUBJECT_H
#define GAMEPROJECT_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer* obs) = 0;

    virtual void removeObserver(Observer* obs) = 0;

    virtual void notifyObservers() const = 0;

protected:
    virtual ~Subject() {}
};


#endif //GAMEPROJECT_SUBJECT_H
