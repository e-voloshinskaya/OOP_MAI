cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 11)


add_executable(lab3 point.h
  point.cpp
  main.cpp
  figure.h
  triangle.h triangle.cpp 
 item.h item.cpp tlinkedlist.h tlinkedlist.cpp)

