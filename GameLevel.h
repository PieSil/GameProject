//
// Created by Pietro on 2019-06-27.
//

#ifndef GAMEPROJECT_GAMELEVEL_H
#define GAMEPROJECT_GAMELEVEL_H

#include "gameValues.h"
#include "Knight.h"
#include "Wizard.h"
#include "MeleeEnemy.h"
#include "RangedEnemy.h"
#include "BossEnemy.h"
#include "Projectile.h"
#include "Fireball.h"
#include "Paralyzing.h"
#include "Map.h"
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include "Collectible.h"
#include "Heart.h"

class GameLevel {
public:
    GameLevel(Herotype heroT);

    GameLevel(); //DEFAULT CONSTRUCTOR ONLY USED FOR UNIT TESTING

    void moveCharacter(GameHero *hero, const Direction &direction, const float &distance);

    void moveCharacter(Enemy *enemy, const float &distance);

    void updateProjectiles(const float &elapsedTime);

    void createMap();

    void createEnemies();

    void createCollectibles();

    void placeEntity(const Entitytype &type, const unsigned short &column, const unsigned short &row);

    const EntityPositions &
    detectMapCollisions(const EntityPositions &prevPosition, GameCharacter *character, const bool &bypassInMap = false);

    const bool detectMapCollisions(std::unique_ptr<Projectile> &projectile);

    void animateCharacters();

    void updateHero();

    void updateEnemies(const float &elapsedTime);

    void updatePhysics(GameCharacter *character);

    void updateLevel(const float &elapsedTime);

    void updateCollectibles();

    const Hitbox createAttackHitbox(GameCharacter *character);

    void updateCombat(GameHero* hero);

    void updateCombat(Enemy* enemy);

    void updateAbility(GameHero *hero);

    void destroy(std::unique_ptr<Projectile> &projectile);

    void destroy(std::unique_ptr<Enemy> &enemy);

    void destroy(std::unique_ptr<Collectible> &collectible);


    /*
void createProjectile(Enemy *enemy, const bool &isFireball = true);
void createProjectile(GameHero *hero, const bool &isFireball = true);
 */


    const std::unique_ptr<GameHero> &getHero() const {
        return hero;
    }

    const std::vector<std::unique_ptr<Enemy>> &getEnemies() const {
        return enemies;
    }

    const Map &getGameMap() const {
        return gameMap;
    }

    const std::vector<std::unique_ptr<Projectile>> &getProjectiles() const {
        return projectiles;
    }

    //used for unit testing
    void setMapTiles(std::vector<Tile> tiles) {
        gameMap.setTiles(tiles);
    }

    const std::vector<std::unique_ptr<Collectible>> &getCollectibles() const {
        return collectibles;
    }

private:
    std::unique_ptr<GameHero> hero;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Projectile>> projectiles;
    std::vector<std::unique_ptr<Collectible>> collectibles;
    Map gameMap;


};


#endif //GAMEPROJECT_GAMELEVEL_H
