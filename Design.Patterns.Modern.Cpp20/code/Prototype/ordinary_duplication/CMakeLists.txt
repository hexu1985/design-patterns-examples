cmake_minimum_required( VERSION 3.15 )

project ( ordinary_duplication LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

add_executable( ordinary_duplication1 main1.cpp )
add_executable( ordinary_duplication2 main2.cpp )
