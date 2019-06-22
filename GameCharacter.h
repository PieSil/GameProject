/**
 * Project Game
 */


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

class GameCharacter {
public: 

    GameCharacter(int x, int y, float h, bool onf = false);
    virtual ~GameCharacter() {};

    virtual void attack();

    virtual void move();

    virtual void jump();

    int getPosX() const {
        return posX;
    }

    void setPosX(int posX) {
        GameCharacter::posX = posX;
    }

    int getPosY() const {
        return posY;
    }

    void setPosY(int posY) {
        GameCharacter::posY = posY;
    }

    float getHealth() const {
        return health;
    }

    void setHealth(float health) {
        GameCharacter::health = health;
    }

    bool isOnFire() const {
        return onFire;
    }

    void setOnFire(bool onFire) {
        GameCharacter::onFire = onFire;
    }

protected:
    int posX;
    int posY;
    float health;
    bool onFire;
};

#endif //_GAMECHARACTER_H