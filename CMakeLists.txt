cmake_minimum_required(VERSION 3.14)
project(GameProject)

set(CMAKE_CXX_STANDARD 11)
set(SFML_DIR "./sfml/2.5.1/lib/cmake/SFML")


add_subdirectory(unit_test)
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

#file(GLOB SOURCES *.h *.cpp)
set(SOURCE_FILES BossEnemy.cpp BossEnemy.h Collectible.cpp Collectible.h Enemy.cpp Enemy.h Fireball.cpp Fireball.h GameCharacter.cpp GameCharacter.h GameHero.cpp GameHero.h Game.cpp Game.h Heart.cpp Heart.h Knight.cpp Knight.h Map.cpp Map.h MeleeEnemy.cpp MeleeEnemy.h Paralyzing.cpp Paralyzing.h Projectile.cpp Projectile.h RangedEnemy.cpp RangedEnemy.h Tile.cpp Tile.h Wizard.cpp Wizard.h GameEntity.cpp GameEntity.h GameWindow.cpp GameWindow.h GameLevel.cpp GameLevel.h Hitbox.cpp Hitbox.h MovingEntity.cpp MovingEntity.h ShootingCharacter.cpp ShootingCharacter.h spriteParameters.h SpriteObserver.cpp SpriteObserver.h SpriteSubject.cpp SpriteSubject.h AnimationManager.cpp AnimationManager.h Animation.cpp Animation.h positionsStruct.h)
add_executable(GameProject main.cpp ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(GameProject sfml-graphics sfml-audio)
target_link_libraries(core sfml-graphics sfml-audio)
