add_executable(test_voronoi test_voronoi.cc)
include_directories(${CAKE_GTEST_DIRECTORY}/googletest/include)
link_libraries(gtest_main)

target_include_directories(test_voronoi PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    ${CAKE_RAYLIB_DIRECTORY}/include)
target_link_libraries(test_voronoi PUBLIC ${CAKE_RAYLIB_DIRECTORY}/lib/libraylib.dylib)

add_executable(test_rope test_rope.cc)
target_include_directories(test_rope PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    ${CAKE_RAYLIB_DIRECTORY}/include)
target_link_libraries(test_rope PUBLIC ${CAKE_RAYLIB_DIRECTORY}/lib/libraylib.dylib)

add_executable(test_gtest test_gtest.cc)
target_include_directories(test_gtest PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    ${CAKE_RAYLIB_DIRECTORY}/include)
target_link_libraries(test_gtest PUBLIC ${CAKE_RAYLIB_DIRECTORY}/lib/libraylib.dylib)

gtest_discover_tests(test_gtest)
