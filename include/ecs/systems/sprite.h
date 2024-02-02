#pragma once

#include "ecs/components/sprite.h"
#include "ecs/entity.h"
#include "ecs/registry.h"
#include "ecs/system.h"
#include "raylib.h"
#include <iostream>

struct SpriteSystem : System {
  virtual void Update(Registry &registry) override {
    for (int e = 1; e <= NumberOfEntity(); e++) {
      if (registry.sprites.count(e) != 0 && registry.transforms.count(e) != 0) {
        registry.sprites[e].dst.x = registry.transforms[e].pos_x;
        registry.sprites[e].dst.y = registry.transforms[e].pos_y;
      }
    }
  }

  virtual void Render(Registry &registry) override {
    for (int e = 1; e <= NumberOfEntity(); e++) {
      if (registry.sprites.count(e) != 0) {
        SpriteComponent& component = registry.sprites[e];
        DrawTexturePro(component.texture, component.src, component.dst, {0, 0},
                       0, WHITE);
      }
    }
  }
};
