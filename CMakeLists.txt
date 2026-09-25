cmake_minimum_required(VERSION 3.16)
project(image_viewer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(image_viewer main.cpp)
target_link_libraries(image_viewer sfml-graphics sfml-window sfml-system)
