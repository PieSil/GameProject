/**
 * Project Game
 */


#include "Knight.h"
#include "gameValues.h"
#include "MovingEntity.h"
#include "GameEntity.h"

/**
 * Knight implementation
 */

Knight::Knight(const float &x, const float &y, const float &str, const bool &onf, const float &h, const bool &facingR,
               const float &s) : GameCharacter(x, y ,str ,onf ,h ,s ,facingR) {
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

Knight::Knight(const Knight &copied) : GameHero(copied){
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}

void Knight::giveHitbox() {
    GameEntity::giveHitbox(sprite.getPosition(), sprite.getTextureRect().width, sprite.getTextureRect().height, KNIGHT_HITBOX_X, KNIGHT_HITBOX_Y,
                           KNIGHT_SCALE);
}

void Knight::move(const Direction& direction, const float& distance) {
    MovingEntity::moveOnX(direction, distance, KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_SCALE, KNIGHT_MOV_ROW,
                        KNIGHT_MOV_LAST_COL);
}

void Knight::initSprite(const float &x, const float &y) {
    MovingEntity::initSprite(x,y, KNIGHT_PATH, KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_SCALE, KNIGHT_IDLE_ROW, KNIGHT_IDLE_COL);
}


