cmake_minimum_required(VERSION 3.27)
project(untitled9)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled9 src/main.cpp
        src/ship.cpp
        inc/ship.h
        src/event.cpp
        inc/event.h)
