cmake_minimum_required(VERSION 3.14)
project(GameProject)

set(CMAKE_CXX_STANDARD 11)
set(SFML_DIR "./sfml/2.5.1/lib/cmake/SFML")


add_subdirectory(unit_test)
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
add_library(core unit_test/runAllTests.cpp)

file(GLOB SOURCES *.h *.cpp)
add_executable(GameProject main.cpp ${SOURCES})
target_link_libraries(GameProject sfml-graphics sfml-audio core)