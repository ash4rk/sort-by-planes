cmake_minimum_required(VERSION 3.10.2)

project(sort_false_points_test)

set(This ExamapleTest)

add_executable(${This} test.cpp
    )

    
target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(${This} PUBLIC
    gtest_main
    ${PROJECT_NAME}
)

add_test(
    NAME ${This}
    COMMAND ${This}
)