cmake_minimum_required(VERSION 3.10)
project(OScourse C)

set(CMAKE_C_STANDARD 99)

add_executable(OScourse linked_list.c test.c linked_list.h bubble_sort.c bubble_sort.h)