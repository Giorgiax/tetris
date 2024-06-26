cmake_minimum_required(VERSION 3.22)
project(tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(tetris main.cpp
        tetramino.cpp
        tetramino.h
        Gioco.cpp
        Gioco.h
        Lingue.cpp
        Lingue.h
        Finestra.cpp
        Finestra.h)
