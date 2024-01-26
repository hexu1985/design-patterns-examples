cmake_minimum_required(VERSION 3.1.0)

project(Command VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Command
    command/Command.hpp
    command/Command.cpp
    command/MacroCommand.hpp
    command/MacroCommand.cpp
    drawer/Drawable.hpp
    drawer/Drawable.cpp
    drawer/DrawCanvas.hpp
    drawer/DrawCanvas.cpp
    drawer/DrawCommand.hpp
    drawer/DrawCommand.cpp
    Main.hpp
    Main.cpp
    )

target_include_directories(Command PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Command Qt5::Widgets)
