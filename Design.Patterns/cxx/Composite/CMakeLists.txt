# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(Composite LANGUAGES CXX)

# list sources
file(GLOB _sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(Composite ${_sources})
