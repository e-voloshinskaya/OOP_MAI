cmake_minimum_required(VERSION 3.10)
project(lab5)

set(CMAKE_CXX_STANDARD 11)


add_executable(lab5 point.h
  point.cpp
  main.cpp
  figure.h
  triangle.h triangle.cpp 
 item.h item.cpp titerator.h tlinkedlist.h tlinkedlist.cpp templates.cpp)
 