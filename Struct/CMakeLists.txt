cmake_minimum_required(VERSION 3.21)
project(Struct C)

set(CMAKE_C_STANDARD 99)

add_executable(Struct main.c Books.h Rents.h Books.c Rents.c)
