cmake_minimum_required(VERSION 3.8)
project(CoEx1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c ex1.h ex1.c)
add_executable(CoEx1 ${SOURCE_FILES})