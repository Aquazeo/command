cmake_minimum_required(VERSION 3.28)

project(command_line C)

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)

add_executable()