//
// Created by Pietro on 2019-07-20.
//

#ifndef GAMEPROJECT_OBSERVER_H
#define GAMEPROJECT_OBSERVER_H

class Observer {
public:
    virtual void update(const float &distanceWalked, const int &enemiesKilled, const bool &bossKilled) = 0;

protected:
    virtual ~Observer() {};
};


#endif //GAMEPROJECT_OBSERVER_H
