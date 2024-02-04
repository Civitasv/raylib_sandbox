add_executable(game game.cc)
target_include_directories(game PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CAKE_RAYLIB_DIRECTORY}/include)
target_link_libraries(game PUBLIC ${CAKE_RAYLIB_DIRECTORY}/lib/libraylib.dylib EnTT::EnTT)

# after build game, please copy the assets dir to bin dir
add_custom_command(
  TARGET game POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/assets/
  ${CMAKE_SOURCE_DIR}/bin/assets/
)

add_subdirectory(ecs)