cmake_minimum_required(VERSION 4.0)
project(programvarudesign)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES src/*.cc) #finds all .cc files recursively in src/

add_executable(game ${SOURCES})
target_include_directories(game PRIVATE include)
