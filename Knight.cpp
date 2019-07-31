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

const SpriteParams Knight::knightParams(
        KNIGHT_PATH, KNIGHT_WIDTH, KNIGHT_HEIGHT, KNIGHT_SCALE, KNIGHT_HITBOX_X, KNIGHT_HITBOX_Y, KNIGHT_IDLE_ROW,
        KNIGHT_IDLE_LAST_COL, KNIGHT_MOV_ROW, KNIGHT_MOV_LAST_COL, KNIGHT_ATT_ROW,
        KNIGHT_ATT_LAST_COL, KNIGHT_ATT_OFFSET, KNIGHT_SHOOT_ROW, KNIGHT_SHOOT_LAST_COL, KNIGHT_DEATH_ROW,
        KNIGHT_DEATH_LAST_COL, KNIGHT_ABILITY_ROW, KNIGHT_ABILITY_LAST_COL);

Knight::Knight(const float &x, const float &y, const float &str, const bool &onf, const float &h, const bool &facingR,
               const float &s) : GameHero(x, y, str, onf, h, facingR, s) {
    initSprite(x, y);
    giveHitbox();

    attackRange = KNIGHT_ATTACK_RANGE;
    attackTimeStep = HERO_ATT_TIMESTEP;
    setupAnimations(getParameters());
    setAttackBehaviour(std::make_shared<MeleeBehaviour>());
}

void Knight::specialBehaviour() {

}

Knight::Knight() : Knight(0, 0) {

}

Knight::Knight(const Knight &copied) : GameHero(copied) {
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}


