#include "ecs/components/keyinput.h"
#include "ecs/components/sprite.h"
#include "ecs/components/text.h"
#include "ecs/components/transform.h"
#include "ecs/entity.h"
#include "ecs/world.h"

#include "raylib.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

int main() {
  World world(WINDOW_WIDTH, WINDOW_HEIGHT);

  Entity bird = world.CreateEntity();
  bird.AddComponent<SpriteComponent>(Rectangle{0, 0, 300, 230},
                                     Rectangle{10, 10, 100, 73},
                                     "assets/sprites/bird.png");
  bird.AddComponent<TransformComponent>(10.0f, 10.0f, 0.0f, 0.0f);
  bird.AddComponent<KeyInputComponent>();
  bird.AddComponent<TextComponent>("Bird", 10, 10, 16, WHITE);

  Entity rope = world.CreateEntity();
  rope.AddComponent<TransformComponent>(10.0f, 10.0f, 0.0f, 0.0f);
  rope.AddComponent<KeyInputComponent>();
  rope.AddComponent<TextComponent>("Rope", 10, 10, 24, WHITE);
  world.DestroyEntity(rope);

  while (!WindowShouldClose()) {
    world.Update();
    world.Render();
  }

  return 0;
}
