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
               const float &s) : GameHero(x, y, str, onf, h, facingR, s), invincible(false) {
    initSprite(x, y);
    giveHitbox();

    attackRange = KNIGHT_ATTACK_RANGE;
    attackTimeStep = HERO_ATT_TIMESTEP;
    abilityTimeStep = KNIGHT_ABILITY_TIMESTEP;
    setupAnimations(getParameters());
    setAttackBehaviour(std::make_shared<MeleeBehaviour>());
}

void Knight::specialBehaviour() {

    bool canUse = false;

    if(abilityAvailable && !isDying() && !isAttacking()) {

        clocks.abilityClock.restart();
        state = EntityState::ABILITY;

        invincible = true;
        clocks.invincibilityClock.restart();
        abilityAvailable = false;
    }


}

Knight::Knight() : Knight(0, 0) {

}

Knight::Knight(const Knight &copied) : GameHero(copied) {
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}

const bool Knight::getDamaged(const float &damage) {

    bool damaged = false;

    //if knight is invincible don't get damaged
    if (!invincible)
        damaged = GameHero::getDamaged(damage);

    return damaged;

}

void Knight::updateStatus() {

    GameHero::updateStatus();

    //if set amount of time has passed since the activation of invincibility turn it off
    if (clocks.invincibilityClock.getElapsedTime().asSeconds() >= 5) {
        invincible = false;
    }
}


