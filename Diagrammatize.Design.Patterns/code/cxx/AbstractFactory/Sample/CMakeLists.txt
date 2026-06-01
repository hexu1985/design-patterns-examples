# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(AbstractFactory LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# list sources
file(GLOB _sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(sources ${_sources})
file(GLOB _sources ${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp)
list(APPEND sources ${_sources})

add_executable(AbstractFactory ${sources})
