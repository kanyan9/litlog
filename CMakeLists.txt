cmake_minimum_required (VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

project(litlog VERSION 1.0)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

add_library(litlog ${SOURCES})

target_include_directories(litlog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(log_test ${CMAKE_CURRENT_SOURCE_DIR}/tests/log_test.cc)
target_link_libraries(log_test litlog)
