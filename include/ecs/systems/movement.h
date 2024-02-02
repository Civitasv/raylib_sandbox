#pragma once

#include "ecs/entity.h"
#include "ecs/registry.h"
#include "ecs/system.h"
#include "raylib.h"
#include <iostream>

struct MovementSystem : System {
  virtual void Update(Registry &registry) override {
    for (int e = 1; e <= NumberOfEntity(); e++) {
      if (registry.transforms.count(e) != 0 && registry.keys.count(e) != 0) {
        // and all entities with a movement component get their velocity
        // set if A, S, D or W is pressed on the keyboard

        if (IsKeyDown(KEY_A)) {
          registry.transforms[e].vel_x = -1.0f;
        }
        if (IsKeyDown(KEY_S)) {
          registry.transforms[e].vel_y = 1.0f;
        }
        if (IsKeyDown(KEY_W)) {
          registry.transforms[e].vel_y = -1.0f;
        }
        if (IsKeyDown(KEY_D)) {
          registry.transforms[e].vel_x = 1.0f;
        }

        if (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
          registry.transforms[e].vel_x = 0.0f;
        }
        if (!IsKeyDown(KEY_S) && !IsKeyDown(KEY_W)) {
          registry.transforms[e].vel_y = 0.0f;
        }
      }
    }
  }
};
