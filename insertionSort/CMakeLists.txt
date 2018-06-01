cmake_minimum_required(VERSION 2.6)
project(insertionSort)

aux_source_directory(. DIR_SRCS)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
add_executable(insertionsort ${DIR_SRCS})
