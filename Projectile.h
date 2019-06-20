/**
 * Project Game
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H

class Projectile {
public: 
    
void move();
    
void characterCollision();
    
void tileCollision();
protected: 
    int damage;
    int posX;
    int posY;
};

#endif //_PROJECTILE_H