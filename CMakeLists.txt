cmake_minimum_required(VERSION 3.10)

project(BearGame)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_definitions(-std=c++11)

add_subdirectory(server)







