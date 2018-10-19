cmake_minimum_required(VERSION 3.9)
project(LabWork4)

set(CMAKE_CXX_STANDARD 11)

add_executable(LabWork4 main.cpp parser/tinyxml2.cpp parser/tinyxml2.h Currency.cpp Currency.h parser/Parser.cpp parser/Parser.h)