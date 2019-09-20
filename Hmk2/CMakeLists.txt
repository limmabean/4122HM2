cmake_minimum_required(VERSION 3.14)
project(Hmk2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Hmk2 Test.cpp ECE_Matrix.cpp ECE_Matrix.h)
