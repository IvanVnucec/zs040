cmake_minimum_required(VERSION 3.18)

project(zs040)
 
include_directories(
    include
)
 
set(SOURCES 
    src/zs040/zs040.c 
    example/main.c
)

add_executable(zs040 ${SOURCES})
