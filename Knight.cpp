/**
 * Project Game
 */


#include "Knight.h"
#include "gameValues.h"
/**
 * Knight implementation
 */

Knight::Knight(const float &x, const float &y, const float &str, const bool &onf, const float &h, const bool &facingR,
               const float &s) : GameHero(x, y, str, onf, h, facingR, s) {
    initSprite(x, y);
    giveHitbox();
}

void Knight::specialBehaviour() {

}
/*
void Knight::updateBehaviour() {
    GameHero::updateBehaviour(KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_SCALE, KNIGHT_MOV_ROW, KNIGHT_MOV_LAST_COL);
}
 */

Knight::Knight() : Knight(0,0) {

}

Knight::Knight(Knight &copied) : GameHero(copied){
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}

void Knight::giveHitbox() {
    GameEntity::giveHitbox(KNIGHT_HITBOX_X, KNIGHT_HITBOX_Y, KNIGHT_SCALE);
}

void Knight::move(const Direction& direction, const float& distance) {
    GameEntity::move(direction, distance, KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_SCALE, KNIGHT_MOV_ROW, KNIGHT_MOV_LAST_COL);
}

void Knight::initSprite(const float &x, const float &y) {
    GameEntity::initSprite(x,y, KNIGHT_PATH, KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_SCALE, KNIGHT_IDLE_ROW, KNIGHT_IDLE_COL);
}


