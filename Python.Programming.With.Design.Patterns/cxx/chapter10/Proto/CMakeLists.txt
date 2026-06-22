cmake_minimum_required(VERSION 3.5)

project(Proto VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

### asan
option(ENABLE_ASAN "Enable AddressSanitizer" ON)

if(ENABLE_ASAN)
    message(STATUS "AddressSanitizer enabled")
    add_compile_options(-g -Wall -fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
endif()

### test data
set(TEST_DATAFILES Swimmers.txt)

foreach(datafile ${TEST_DATAFILES})
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${datafile}
        #COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/${datafile}
                ${CMAKE_CURRENT_BINARY_DIR}/${datafile}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${datafile}
        COMMENT "Copying test datafile ${datafile}"
    )
endforeach()

add_custom_target(copy_test_datafile ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Swimmers.txt
)

set(PROJECT_SOURCES)
file(GLOB PROJECT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Proto
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(Proto
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(Proto PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

add_dependencies(Proto copy_test_datafile)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Proto)
endif()
