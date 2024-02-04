#pragma once

#include "ecs/components/sprite.h"
#include "ecs/components/transform.h"
#include "ecs/system.h"
#include "entt/entity/fwd.hpp"
#include "raylib.h"

#include "entt/entt.hpp"

struct SpriteSystem : System {
  virtual void Update(entt::registry &registry) override {
    registry.view<const TransformComponent, SpriteComponent>().each(
        [](const auto &transform, auto &sprite) {
          sprite.dst.x = transform.pos_x;
          sprite.dst.y = transform.pos_y;
        });
  }

  virtual void Render(entt::registry &registry) override {
    registry.view<const SpriteComponent>().each([](const auto &sprite) {
      DrawTexturePro(sprite.texture, sprite.src, sprite.dst, {0, 0}, 0, WHITE);
    });
  }
};
