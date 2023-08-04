cmake_minimum_required(VERSION 3.1.0)

project(Observer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Observer
    Main.cpp
    Random.cpp
    Random.hpp
    Observer.cpp
    Observer.hpp
	DigitObserver.cpp
	DigitObserver.hpp
	GraphObserver.cpp
	GraphObserver.hpp
	NumberGenerator.cpp
	NumberGenerator.hpp
	RandomNumberGenerator.cpp
	RandomNumberGenerator.hpp
    FrameObserver.cpp
    FrameObserver.hpp
    )

target_link_libraries(Observer Qt5::Widgets pthread)
