cmake_minimum_required(VERSION 2.6)

project(selectionSort)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

aux_source_directory(. DIR_SRCS)

add_executable(selectionsort ${DIR_SRCS})
