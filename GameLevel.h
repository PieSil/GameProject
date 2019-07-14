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
#include "Projectile.h"
#include "Fireball.h"
#include "Paralyzing.h"
#include "Map.h"
#include <algorithm>
#include <fstream>
#include <typeinfo>

class GameLevel {
public:
    GameLevel(Herotype heroT);

    GameLevel(); //DEFAULT CONSTRUCTOR ONLY USED FOR UNIT TESTING

    void moveCharacter(GameHero *hero, const Direction &direction, const float &distance);

    void moveCharacter(Enemy *enemy, const float &distance);

    void updateProjectiles(const float &elapsedTime);

    void createProjectile(Enemy *enemy, const bool &isFireball = true);
    void createProjectile(GameHero *hero, const bool &isFireball = true);

    void createMap();

    void detectMapCollisions(const EntityPositions &prevPosition, GameCharacter *character);

    const bool detectMapCollisions(std::unique_ptr<Projectile> &projectile);

    void animateCharacters();

    void updateHero();

    void updateEnemies(const float &elapsedTime);

    void updatePhysics(GameCharacter *character);

    void updateLevel(const float &elapsedTime);

    const Hitbox createAttackHitbox(GameCharacter *character);

    void updateCombat(GameHero* hero);

    void updateCombat(Enemy* enemy);

    void destroyProjectile(std::unique_ptr<Projectile> &projectile);

    const std::unique_ptr<GameHero> &getHero() const {
        return hero;
    }

    const std::vector<std::unique_ptr<Enemy>> &getEnemies() const {
        return enemies;
    }

    const Map &getGameMap() const {
        return gameMap;
    }

    void setGameMap(const Map &gameMap) {
        GameLevel::gameMap = gameMap;
    }

    const std::vector<std::unique_ptr<Projectile>> &getProjectiles() const {
        return projectiles;
    }

private:
    std::unique_ptr<GameHero> hero;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Projectile>> projectiles;
    Map gameMap;


};


#endif //GAMEPROJECT_GAMELEVEL_H
