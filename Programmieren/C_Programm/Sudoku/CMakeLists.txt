cmake_minimum_required(VERSION 3.27)
project(Sudoku C)

set(CMAKE_C_STANDARD 11)

add_executable(Sudoku main.c
        validation.c
        userinput.c)
