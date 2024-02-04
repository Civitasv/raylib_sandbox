#pragma once

#include "ecs/systems/movement.h"
#include "ecs/systems/sprite.h"
#include "ecs/systems/transform.h"
#include "raylib.h"
#include <cstddef>

#include "entt/entt.hpp"

struct Entity;
struct World {
  void Update() {
    sprite_system.Update(registry);
    transform_system.Update(registry);
    movement_system.Update(registry);
  }

  void Render() {
    BeginDrawing();
    ClearBackground(BLACK);

    sprite_system.Render(registry);

    EndDrawing();
  }

  Entity CreateEntity();

  World(std::size_t width, std::size_t height) : width(width), height(height) {
    InitWindow(width, height, "Raylib Sandbox");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    // It is resizable
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // Enable Multi Sampling Anti Aliasing 4x (if available)
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    is_running = true;
  }

  ~World() { CloseWindow(); }

  std::size_t width;
  std::size_t height;
  bool is_running;

  SpriteSystem sprite_system;
  TransformSystem transform_system;
  MovementSystem movement_system;

  entt::registry registry;
};
