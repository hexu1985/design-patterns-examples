cmake_minimum_required( VERSION 3.15 )

project(classic_implementation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

### test script
set(TEST_DATA_FILES capitals.txt)

foreach(script ${TEST_DATA_FILES})
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${script}
        #COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/${script}
                ${CMAKE_CURRENT_BINARY_DIR}/${script}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${script}
        COMMENT "Copying file ${script}"
    )
endforeach()

add_custom_target(copy_data_files ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/capitals.txt
)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
add_executable( classic_implementation ${SOURCES} ${HEADERS} )
add_dependencies(classic_implementation copy_data_files)
