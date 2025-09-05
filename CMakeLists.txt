cmake_minimum_required(VERSION 3.15)
project(notepad)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(notepad
    src/main.cpp
)

target_include_directories(notepad PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/text/text.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})