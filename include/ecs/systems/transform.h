#pragma once

#include "ecs/entity.h"
#include "ecs/registry.h"
#include "ecs/system.h"

struct TransformSystem : System {
  float dt = 1.0f;

  virtual void Update(Registry& registry) override {
    for (int e = 1; e <= NumberOfEntity(); e++) {
      if (registry.transforms.count(e) != 0){
        registry.transforms[e].pos_x += registry.transforms[e].vel_x * dt;
        registry.transforms[e].pos_y += registry.transforms[e].vel_y * dt;
      }
    }
  }
};
