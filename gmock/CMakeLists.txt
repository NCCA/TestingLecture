cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

project(gmock)
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

enable_testing()

add_executable(gmock main.cpp MockTurtle.h Painter.h Turtle.h)
target_link_libraries(gmock PRIVATE GTest::gtest GTest::gtest_main GTest::gmock)

gtest_discover_tests(gmock)
