cmake_minimum_required(VERSION 3.20)
project(lab1)

set(CMAKE_CXX_STANDARD 11)


add_executable(lab1 
  main.cpp
  figure.h
  triangle.h triangle.cpp 
 "rectangle.h" "rectangle.cpp" "square.h" "square.cpp")