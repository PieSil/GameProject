/**
 * Project Game
 */


#ifndef _GAMECHARACTER_H
#define _GAMECHARACTER_H

class GameCharacter {
public: 
    
void attack();
    
void move();
    
void jump();
protected: 
    float health;
    int posX;
    int posY;
    bool onFire;
};

#endif //_GAMECHARACTER_H