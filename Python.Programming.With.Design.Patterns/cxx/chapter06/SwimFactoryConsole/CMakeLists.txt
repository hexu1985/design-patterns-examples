cmake_minimum_required( VERSION 3.15 )

project ( SwimFactoryConsole LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

### test data
set(TEST_DATAFILES 100free.txt 500free.txt)

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
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/100free.txt
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/500free.txt
)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_executable( SwimFactoryConsole ${SOURCES} )
add_dependencies(SwimFactoryConsole copy_test_datafile)
