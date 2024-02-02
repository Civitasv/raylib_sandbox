#pragma once

#include "ecs/component.h"

struct TransformComponent : public Component {
  float pos_x;
  float pos_y;
  float vel_x;
  float vel_y;

  TransformComponent() {}

  TransformComponent(float pos_x, float pos_y, float vel_x, float vel_y)
      : pos_x(pos_x), pos_y(pos_y), vel_x(vel_x), vel_y(vel_y) {}
};
