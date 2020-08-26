cmake_minimum_required(VERSION 3.10)

project(BearGame)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/BearGame/)
include_directories(${PROJECT_SOURCE_DIR}/BearGame/server)
include_directories(${PROJECT_SOURCE_DIR}/BearGame/3rd)

link_directories(${PROJECT_SOURCE_DIR}/lib)
link_directories(${PROJECT_SOURCE_DIR}/BearGame/3rd/lib)

set(CXX_FLAGS
    -Wall
    -Wextra
    -Werror
)


add_subdirectory(BearGame/3rd)
add_subdirectory(BearGame/base)
add_subdirectory(BearGame/server)