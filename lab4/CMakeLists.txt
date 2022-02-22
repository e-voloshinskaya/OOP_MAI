cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 11)


add_executable(lab4 point.h
  point.cpp
  main.cpp
  figure.h
  triangle.h triangle.cpp 
 item.h item.cpp tlinkedlist.h tlinkedlist.cpp templates.cpp)
 