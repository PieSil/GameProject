/**
 * Project Game
 */


#include "Knight.h"
#include "defaultValues.h"
/**
 * Knight implementation
 */

Knight::Knight(int x, int y, bool onf, float h) : GameHero(x, y, onf, h) {
    loadTexture("../GameAssets/Sprites/Player/Knight/Knight.png");
    sprite.setTextureRect(sf::IntRect(0,KNIGHT_HEIGHT*0,KNIGHT_WIDTH,KNIGHT_HEIGHT*1));
}

void Knight::specialBehaviour() {

}


