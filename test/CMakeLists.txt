add_executable(test_voronoi test_voronoi.cc)
target_include_directories(test_voronoi PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    ${CAKE_RAYLIB_DIRECTORY}/include)
target_link_libraries(test_voronoi PUBLIC ${CAKE_RAYLIB_DIRECTORY}/lib/libraylib.dylib)
