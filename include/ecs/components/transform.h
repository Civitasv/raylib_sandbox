#pragma once

struct TransformComponent {
  float pos_x;
  float pos_y;
  float vel_x;
  float vel_y;

  TransformComponent() = default;
  TransformComponent(const TransformComponent&) = default;
};
