cmake_minimum_required(VERSION 3.14)
project(GameProject)

set(CMAKE_CXX_STANDARD 11)
set(SFML_DIR "./sfml/2.5.1/lib/cmake/SFML")


add_subdirectory(unit_test)
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
add_library(core unit_test/runAllTests.cpp)

#file(GLOB SOURCES *.h *.cpp)
set(SOURCE_FILES main.cpp BossEnemy.cpp BossEnemy.h Collectible.cpp Collectible.h Enemy.cpp Enemy.h Fireball.cpp Fireball.h GameCharacter.cpp GameCharacter.h GameHero.cpp GameHero.h GameLevel.cpp GameLevel.h Heart.cpp Heart.h Knight.cpp Knight.h Map.cpp Map.h MeleeEnemy.cpp MeleeEnemy.h Paralyzing.cpp Paralyzing.h Projectile.cpp Projectile.h RangedEnemy.cpp RangedEnemy.h Tile.cpp Tile.h Wizard.cpp Wizard.h)
add_executable(GameProject main.cpp ${SOURCE_FILES})
target_link_libraries(GameProject sfml-graphics sfml-audio core)