cmake_minimum_required(VERSION 3.12.0)
project(day3_aoc2020 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)
include_directories(${INCLUDE_DIR})
include(CTest)
enable_testing()

add_executable(day3_aoc2020 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
