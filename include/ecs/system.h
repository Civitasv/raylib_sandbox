#pragma once

#include "entt/entt.hpp"

/// System represents calcute logic, only function, no variable.
struct System {
  virtual void Update(entt::registry &registry) {}
  virtual void Render(entt::registry &registry) {}
};
