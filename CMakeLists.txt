cmake_minimum_required(VERSION 4.0)
project(programvarudesign)

set(CMAKE_CXX_STANDARD 20)

# GAME EXECUTABLE
file(GLOB_RECURSE SOURCES src/*.cc) #finds all .cc files recursively in src/
add_executable(game ${SOURCES})
target_include_directories(game PRIVATE include)


# TEST EXECUTABLE (exciting!)
file(GLOB_RECURSE TEST_SOURCES tests/*.cc)
## Include all the programs source files, except main (since the tests gen their own!)
file(GLOB_RECURSE GAME_SOURCES src/*.cc)
list(FILTER GAME_SOURCES EXCLUDE REGEX ".*main\\.cc$")

add_executable(tests ${TEST_SOURCES} ${GAME_SOURCES})
target_include_directories(tests PRIVATE include)
