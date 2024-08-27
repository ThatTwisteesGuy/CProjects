cmake_minimum_required(VERSION 3.28)
project(MatrixLibrary C)

set(CMAKE_C_STANDARD 11)

add_executable(MatrixLibrary
        MatrixFunctions.c
        matrix.h
        main.c)
