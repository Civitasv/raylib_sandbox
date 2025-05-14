#pragma once

#include "ecs/component.h"
#include "raylib.h"
#include <string>

struct TextComponent: public Component {
  std::string text;
  int pos_x;
  int pos_y;
  int font_size;
  Color color;

  TextComponent() = default;
  TextComponent(const TextComponent &) = default;

  TextComponent(const std::string &text, int pos_x, int pos_y,
                int font_size = 16, Color color = BLACK)
      : text(text), pos_x(pos_x), pos_y(pos_y), font_size(font_size),
        color(color) {}
};
