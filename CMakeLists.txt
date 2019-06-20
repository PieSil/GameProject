cmake_minimum_required(VERSION 3.14)
project(GameProject)

set(CMAKE_CXX_STANDARD 11)
set(SFML_DIR "‎usr/local/Cellar/sfml/2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_subdirectory(unit_test)

file(GLOB SOURCES *.h *.cpp)
set(SOURCE_FILES ${SOURCES})
add_executable(GameProject main.cpp ${SOURCES})
add_library(core ${SOURCE_FILES})
target_link_libraries(GameProject sfml-graphics sfml-audio core)