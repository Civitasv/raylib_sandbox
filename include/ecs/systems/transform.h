#pragma once

#include "ecs/components/transform.h"
#include "ecs/system.h"
#include "entt/entt.hpp"

struct TransformSystem : System {
  float dt = 1.0f;

  virtual void Update(entt::registry &registry) override {
    registry.view<TransformComponent>().each([this](auto &transform) {
      transform.pos_x += transform.vel_x * dt;
      transform.pos_y += transform.vel_y * dt;
    });
  }
};
