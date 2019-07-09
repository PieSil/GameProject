//
// Created by Pietro on 2019-06-27.
//

#ifndef GAMEPROJECT_GAMELEVEL_H
#define GAMEPROJECT_GAMELEVEL_H

#include "gameValues.h"
#include "Knight.h"
#include "Wizard.h"
#include "MeleeEnemy.h"
#include "BossEnemy.h"
#include "Map.h"

class GameLevel {
public:
    GameLevel(Herotype heroT);

    GameLevel(); //DEFAULT CONSTRUCTOR ONLY USED FOR UNIT TESTING

    void moveCharacter(GameHero *hero, const Direction &direction, const float &distance);

    void moveCharacter(Enemy *enemy, const float &distance);

    void moveCharacter(GameCharacter* character, const Direction &direction, const float &distance);

    void updatePhysics(GameCharacter *character);

    void createMap();

    void detectCollisions(const entityPositions &prevPosition, GameCharacter *character);

    void animateCharacters();

    void updateHero();

    void updateEnemies(const float &elapsedTime);

    void updateLevel(const float &elapsedTime);

    const Hitbox createAttackHitbox(GameCharacter *character);

    void updateCombat(GameHero* hero);

    void updateCombat(Enemy* enemy);

    const std::unique_ptr<GameHero> &getHero() const {
        return hero;
    }

    const std::list<std::unique_ptr<Enemy>> &getEnemies() const {
        return enemies;
    }

    const Map &getGameMap() const {
        return gameMap;
    }

    void setGameMap(const Map &gameMap) {
        GameLevel::gameMap = gameMap;
    }

private:
    std::unique_ptr<GameHero> hero;
    std::list<std::unique_ptr<Enemy>> enemies;
    Map gameMap;


};


#endif //GAMEPROJECT_GAMELEVEL_H
