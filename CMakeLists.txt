cmake_minimum_required(VERSION 3.10)

project(BearGame)

include_directories(${PROJECT_SOURCE_DIR})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(BearGame/3rd)
add_subdirectory(BearGame/server)



