cmake_minimum_required(VERSION 3.14)

add_subdirectory(googletest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(gtest_SOURCE_FILES runAllTests.cpp)
add_executable(runAllTests ${gtest_SOURCE_FILES})
target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core)