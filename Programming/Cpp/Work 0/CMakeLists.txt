cmake_minimum_required(VERSION 3.8)
project(Work)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c Point.h Set.h Set.c)
add_executable(Work ${SOURCE_FILES})