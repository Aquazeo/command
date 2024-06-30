cmake_minimum_required(VERSION 3.28)

project(algorithm C)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)

add_executable(algorithm ${SRC})
