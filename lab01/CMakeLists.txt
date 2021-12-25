set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
cmake_minimum_required(VERSION 3.5)

project (oop_01)

set(SOURCES
    britishmoney.cpp
    main.cpp
)

add_executable(oop_01 ${SOURCES})

target_include_directories(oop_01
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)