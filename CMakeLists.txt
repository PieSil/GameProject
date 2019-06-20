cmake_minimum_required(VERSION 3.14)
project(GameProject)

set(CMAKE_CXX_STANDARD 11)
set(SFML_DIR "‎usr/local/Cellar/sfml/2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
file(GLOB SOURCES *.h *.cpp)
set(SOURCE FILES)
add_executable(GameProject main.cpp ${SOURCE_FILES} ${SOURCES})
target_link_libraries(GameProject sfml-graphics sfml-audio)