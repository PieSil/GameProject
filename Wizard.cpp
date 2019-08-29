/**
 * Project Game
 */


#include "Wizard.h"
#include "MovingEntity.h"
#include "GameEntity.h"

/**
 * Wizard implementation
 */


const SpriteParams Wizard::wizardParams(
        WIZARD_PATH, WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_HITBOX_X, WIZARD_HITBOX_Y, WIZARD_IDLE_ROW,
        WIZARD_IDLE_LAST_COL, WIZARD_MOV_ROW, WIZARD_MOV_LAST_COL, WIZARD_ATT_ROW,
        WIZARD_ATT_LAST_COL, WIZARD_ATT_OFFSET, WIZARD_SHOOT_ROW, WIZARD_SHOOT_LAST_COL, WIZARD_DEATH_ROW,
        WIZARD_DEATH_LAST_COL, WIZARD_ABILITY_ROW, WIZARD_ABILITY_LAST_COL);

Wizard::Wizard(const float &x, const float &y, const float &str, const bool &onf, const int &m, const float &h,
               const bool &facingR, const float &s)
        : GameHero(x, y, str, onf, h, facingR, s), mana(m) {
    initSprite(x, y);
    giveHitbox();
    setupAnimations(getParameters());
    setupAudio();
    attackRange = WIZARD_ATTACK_RANGE;
    attackTimeStep = HERO_ATT_TIMESTEP;
    abilityTimeStep = WIZARD_ABILITY_TIMESTEP,
    setAttackBehaviour(std::make_shared<ShootingBehaviour>());
}

/*
void Wizard::updateBehaviour() {
    GameHero::updateBehaviour(WIZARD_WIDTH, WIZARD_HEIGHT, WIZARD_SCALE, WIZARD_MOV_ROW, WIZARD_MOV_LAST_COL);
}
 */

Wizard::Wizard() : Wizard(0, 0) {

}

Wizard::Wizard(const Wizard &copied) : mana(copied.getMana()), GameHero(copied) {
    initSprite(copied.getSprite().getPosition().x, copied.getSprite().getPosition().y);
    giveHitbox();
}

void Wizard::specialBehaviour(std::vector<std::unique_ptr<Projectile>>& levelProjectiles) {


    if(abilityAvailable && !isDying() && !isAttacking()) {

        clocks.abilityClock.restart();
        state = EntityState::ABILITY;

        levelProjectiles.push_back(std::unique_ptr<Paralyzing>(new Paralyzing(this)));

        audioPlayer.play(SoundID::PARALYZING);

        decreaseMana(PARA_COST);
    }

}

const std::pair<bool, Hitbox> Wizard::attack(const bool &bypassClock) {

    std::pair<bool, Hitbox> attackPair;

    attackPair.first = false;

    if (hasEnoughMana(FIREB_COST)) {

        attackPair = GameCharacter::attack(bypassClock);
        if (attackPair.first) {
            decreaseMana(FIREB_COST);
        }
    }

    return attackPair;
}

const bool Wizard::hasEnoughMana(const int &cost) {

    bool hasEnough = false;

    if (mana >= cost) {
        hasEnough = true;
    }

    return hasEnough;
}

void Wizard::regenerateMana() {
    if (clocks.manaClock.getElapsedTime().asSeconds() >= MANA_REGENERATE_TIMESTEP) {
        clocks.manaClock.restart();
        mana += MANA_REGENERATE_VALUE;
        if (mana > DEF_MANA) {
            mana = DEF_MANA;
        }
    }
}

void Wizard::updateStatus() {
    GameHero::updateStatus();

    regenerateMana();

    abilityAvailable = hasEnoughMana(PARA_COST);
}

void Wizard::decreaseMana(const unsigned short & amount) {
    mana -= amount;

    if (mana < 0) {
        mana = 0;
    }

}

void Wizard::setupAudio() {
    GameHero::setupAudio();
    audioPlayer.insertSound(SoundID::FIREBALL, FIREB_SOUND_PATH, STANDARD_PITCH, DEF_SFX_VOLUME);
    audioPlayer.insertSound(SoundID::PARALYZING, PARA_SOUND_PATH, PARALYZING_PITCH, DEF_SFX_VOLUME);
}
