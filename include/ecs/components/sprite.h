#pragma once

#include "raylib.h"
#include <iostream>

struct SpriteComponent {
  Rectangle src;
  Rectangle dst;
  Texture2D texture;

  SpriteComponent() = default;
  SpriteComponent(const SpriteComponent &) = default;

  SpriteComponent(const Rectangle &src, const Rectangle &dst,
                  const char *texture_path)
      : src(src), dst(dst) {
    std::cout << "Load texture: " << texture_path << '\n';
    texture = LoadTexture(texture_path);
  }

  ~SpriteComponent() {
    std::cout << "Unload" << '\n';
    UnloadTexture(texture);
  }
};
