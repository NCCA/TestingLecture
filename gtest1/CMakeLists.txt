cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

project(GTest1)
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

enable_testing()

add_executable(gtest1 main.cpp  str2double.cpp  str2double.h)
target_link_libraries(gtest1 PRIVATE GTest::gtest GTest::gtest_main )

gtest_discover_tests(gtest1)
