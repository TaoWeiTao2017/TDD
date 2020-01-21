# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(TDD LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# example library
# add_library(sum_integers sum_integers.cpp)

# main code
# add_executable(sum_up main.cpp)
# target_link_libraries(sum_up sum_integers)

# find boost library
find_package(GTest 1.8 REQUIRED COMPONENTS test main)

message(STATUS "GTEST version: ${GTEST_VERSION}")
message(STATUS "GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}")

add_executable(soundex_test "")

target_sources(soundex_test
    PRIVATE
    soundex_test.cc
)

target_include_directories(soundex_test
  PRIVATE
  ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(soundex_test
    PRIVATE
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
)

enable_testing()

add_test(
  NAME google_test
  COMMAND $<TARGET_FILE:soundex_test>
)
