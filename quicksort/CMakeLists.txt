cmake_minimum_required(VERSION 2.6)

project(quicksort)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

add_executable(quicksort main.c)
