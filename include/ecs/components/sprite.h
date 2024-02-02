#pragma once

#include "ecs/component.h"
#include "raylib.h"
#include <iostream>

struct SpriteComponent : public Component {
  Rectangle src;
  Rectangle dst;
  Texture2D texture;

  SpriteComponent() {}

  SpriteComponent(const Rectangle &src, const Rectangle &dst,
                  const Texture2D &texture)
      : src(src), dst(dst), texture(texture) {}

  ~SpriteComponent() { std::cout << "Unload" << '\n'; UnloadTexture(texture); }
};
