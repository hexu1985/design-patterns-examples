cmake_minimum_required(VERSION 3.1.0)

project(app VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(State 
    SafeFrame.cpp
    SafeFrame.hpp
    Context.cpp
    Context.hpp
    DayState.cpp
    DayState.hpp
    NightState.cpp
    NightState.hpp
    State.cpp
    State.hpp
    Main.cpp)

target_link_libraries(State Qt5::Widgets pthread)
