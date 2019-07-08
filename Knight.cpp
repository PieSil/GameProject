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

const SpriteParams Knight::knightParams(KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_HITBOX_X, KNIGHT_HITBOX_Y, KNIGHT_SCALE,
                                        KNIGHT_PATH, KNIGHT_IDLE_ROW,
                                        KNIGHT_IDLE_LAST_COL, KNIGHT_MOV_ROW, KNIGHT_MOV_LAST_COL, KNIGHT_ATT_ROW,
                                        KNIGHT_ATT_LAST_COL, KNIGHT_ATT_OFFSET);

Knight::Knight(const float &x, const float &y, const float &str, const bool &onf, const float &h, const bool &facingR,
               const float &s) : GameHero(x, y, str, onf, h, facingR, s) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());

}

void Knight::specialBehaviour() {

}

Knight::Knight() : Knight(0, 0) {

}

Knight::Knight(const Knight &copied) : GameHero(copied) {
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}


