cmake_minimum_required(VERSION 3.5)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB CONTEST1_HEADERS
    Contest\ 1/first_contest.h
)

file(GLOB CONTEST1_SOURCES
    Contest\ 1/*.cpp
    Contest\ 1/*/*.cpp
    Contest\ 1/*/*/*.cpp
)

add_executable(Contest1 ${CONTEST1_HEADERS} ${CONTEST1_SOURCES})
