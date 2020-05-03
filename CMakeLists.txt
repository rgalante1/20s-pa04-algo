cmake_minimum_required(VERSION 3.10)
project(20s-pa04-algo)
set(EXE_NAME Project4)

set (input01 "")

foreach(file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)
add_executable(${EXE_NAME} main.cpp
    search.h)
