#include "game.h"
#include "ecs/components/keyinput.h"
#include "ecs/components/sprite.h"
#include "ecs/components/transform.h"
#include "ecs/entity.h"
#include "ecs/world.h"

#include "raylib.h"
#include <memory>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

int main() {
  World world(WINDOW_WIDTH, WINDOW_HEIGHT);
  Entity bird = CreateEntity();

  std::unique_ptr<SpriteComponent> sprite_component_for_bird = std::make_unique<SpriteComponent>(
      Rectangle{0, 0, 300, 230}, Rectangle{10, 10, 100, 73},
      LoadTexture("assets/sprites/bird.png"));
  world.registry.sprites[bird] = *sprite_component_for_bird;

  world.registry.transforms[bird] =
      TransformComponent{10.0f, 10.0f, 0.0f, 0.0f};
  world.registry.keys[bird] = KeyInputComponent{};

  while (!WindowShouldClose()) {
    world.Update();
    world.Render();
  }

  return 0;
}
