add_executable(sandbox sandbox.cc)
target_include_directories(sandbox PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    ${CAKE_RAYLIB_DIRECTORY}/include)
target_link_libraries(sandbox PUBLIC
    ${CAKE_RAYLIB_DIRECTORY}/lib/libraylib.dylib)
