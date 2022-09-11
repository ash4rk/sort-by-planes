cmake_minimum_required(VERSION 3.10.2)

project(sort_false_points)

add_executable(${PROJECT_NAME} main.cpp
                            src/operations.cpp
                            src/solution.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)