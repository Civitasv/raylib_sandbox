cmake_minimum_required(VERSION 3.20)
project(basic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CAKE_OTHER_DIRECTORIES_DIRECTORY ${CMAKE_SOURCE_DIR}/packages/other_packages)
set(CAKE_RAYLIB_DIRECTORY ${CAKE_OTHER_DIRECTORIES_DIRECTORY}/raylib-5.0_macos)
set(CAKE_ENTT_DIRECTORY ${CAKE_OTHER_DIRECTORIES_DIRECTORY}/entt-v3.13.1)
set(CAKE_LUA_DIRECTORY ${CAKE_OTHER_DIRECTORIES_DIRECTORY}/lua-5.4.7/src)
set(CAKE_GTEST_DIRECTORY ${CAKE_OTHER_DIRECTORIES_DIRECTORY}/googletest-1.17.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)

add_subdirectory(${CAKE_ENTT_DIRECTORY})
add_subdirectory(${CAKE_LUA_DIRECTORY})
add_subdirectory(${CAKE_GTEST_DIRECTORY})

include(CTest)
include(GoogleTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)

