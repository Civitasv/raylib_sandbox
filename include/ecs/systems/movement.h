#pragma once

#include "ecs/components/keyinput.h"
#include "ecs/components/sprite.h"
#include "ecs/components/transform.h"
#include "ecs/system.h"
#include "entt/entity/fwd.hpp"
#include "raylib.h"

struct MovementSystem : System {
  virtual void Update(entt::registry &registry) override {
    registry.view<KeyInputComponent>().each([](auto &keyinput) {
      if (IsKeyDown(KEY_A)) {
        keyinput.key_down = KEY_A;
      } else if (IsKeyDown(KEY_D)) {
        keyinput.key_down = KEY_D;
      } else if (IsKeyDown(KEY_W)) {
        keyinput.key_down = KEY_W;
      } else if (IsKeyDown(KEY_S)) {
        keyinput.key_down = KEY_S;
      } else {
        keyinput.key_down = GetKeyPressed();
      }
    });
    registry.view<TransformComponent, const KeyInputComponent>().each(
        [](auto &transform, const auto &keyinput) {
          // and all entities with a movement component get their velocity
          // set if A, S, D or W is pressed on the keyboard

          if (keyinput.key_down == KEY_A) {
            transform.vel_x = -1.0f;
          }
          if (keyinput.key_down == KEY_S) {
            transform.vel_y = 1.0f;
          }
          if (keyinput.key_down == KEY_W) {
            transform.vel_y = -1.0f;
          }
          if (keyinput.key_down == KEY_D) {
            transform.vel_x = 1.0f;
          }

          if (keyinput.key_down != KEY_A && keyinput.key_down != KEY_D) {
            transform.vel_x = 0.0f;
          }
          if (keyinput.key_down != KEY_S && keyinput.key_down != KEY_W) {
            transform.vel_y = 0.0f;
          }
        });
  }
};
