cmake_minimum_required(VERSION 3.10.2)

project(sort_false_points)

add_executable(${PROJECT_NAME} main.cpp
                            src/operations.cpp
                            src/solution.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_subdirectory(googletest)

set(Headers
    include/operations.hpp
    include/plane.hpp
    include/point.hpp
    include/solution.hpp
)
set(Sources
    src/operations.cpp
    src/solution.cpp
)
set(libname
${PROJECT_NAME}+lib)

add_subdirectory(test)

add_library(libsortfalse STATIC ${Sources} ${Headers})