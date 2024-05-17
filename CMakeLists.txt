cmake_minimum_required(VERSION 3.27)
project(CDataframe C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CDataframe
        CDataframe.c
        CDataframe.h
        column.c
        column.h
        list.c
        list.h
        main.c)
