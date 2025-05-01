cmake_minimum_required (VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

project(litlog VERSION 1.0)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

# third_party lib
find_package(nlohmann_json 3.12.0 REQUIRED)

add_library(litlog ${SOURCES})

target_include_directories(litlog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(litlog PRIVATE nlohmann_json::nlohmann_json)

add_executable(log_test ${CMAKE_CURRENT_SOURCE_DIR}/tests/log_test.cc)
target_link_libraries(log_test litlog)