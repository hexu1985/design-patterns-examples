cmake_minimum_required( VERSION 3.15 )

project ( observer_with_boost_signals2 LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS signals2)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
add_executable( observer_with_boost_signals2 ${SOURCES} ${HEADERS} )
target_link_libraries( observer_with_boost_signals2 Boost::signals2)

