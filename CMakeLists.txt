cmake_minimum_required(VERSION 3.10)
project(robot_servo_system VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BUILD_PEDANTIC_DOC "Build the project with -Wall, -Wextra and -Wpedantic.")

add_subdirectory(src)