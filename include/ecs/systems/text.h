#pragma once

#include "ecs/components/text.h"
#include "ecs/system.h"
#include "entt/entity/fwd.hpp"
#include "raylib.h"

#include "entt/entt.hpp"

struct TextSystem : System {
  virtual void Update(entt::registry &registry) override {}

  virtual void Render(entt::registry &registry) override {
    registry.view<const TextComponent>().each([](const auto &text) {
      DrawText(text.text.data(), text.pos_x, text.pos_y, text.font_size, text.color);
    });
  }
};
