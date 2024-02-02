cmake_minimum_required(VERSION 3.20)
project(basic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CAKE_OTHER_DIRECTORIES_DIRECTORY ${CMAKE_SOURCE_DIR}/packages/other_packages)
set(CAKE_RAYLIB_DIRECTORY ${CAKE_OTHER_DIRECTORIES_DIRECTORY}/raylib-5.0_macos)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)

add_subdirectory(src)
add_subdirectory(test)
