cmake_minimum_required(VERSION 3.1.0)

project(Interpreter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Interpreter
    language/CommandListNode.cpp
    language/CommandListNode.hpp
    language/CommandNode.cpp
    language/CommandNode.hpp
    language/Context.cpp
    language/Context.hpp
    language/ExecuteException.hpp
    language/Executor.hpp
    language/ExecutorFactory.hpp
    language/InterpreterFacade.cpp
    language/InterpreterFacade.hpp
    language/Node.cpp
    language/Node.hpp
    language/ParseException.hpp
    language/PrimitiveCommandNode.cpp
    language/PrimitiveCommandNode.hpp
    language/ProgramNode.cpp
    language/ProgramNode.hpp
    language/RepeatCommandNode.cpp
    language/RepeatCommandNode.hpp
    turtle/TurtleCanvas.cpp
    turtle/TurtleCanvas.hpp
    main.cpp
    )

target_include_directories(Interpreter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Interpreter Qt5::Widgets)
