#include "game.h"
#include "ecs/components/keyinput.h"
#include "ecs/components/sprite.h"
#include "ecs/components/transform.h"
#include "ecs/world.h"

#include "raylib.h"
#include <memory>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

int main() {
  World world(WINDOW_WIDTH, WINDOW_HEIGHT);
  const auto bird = world.registry.create();

  world.registry.emplace<SpriteComponent>(bird, Rectangle{0, 0, 300, 230},
                                          Rectangle{10, 10, 100, 73},
                                          "assets/sprites/bird.png");
  world.registry.emplace<TransformComponent>(bird, 10.0f, 10.0f, 0.0f, 0.0f);
  world.registry.emplace<KeyInputComponent>(bird);

  while (!WindowShouldClose()) {
    world.Update();
    world.Render();
  }

  return 0;
}
