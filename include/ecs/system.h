#pragma once

/// System represents calcute logic, only function, no variable.
#include "ecs/entity.h"
#include "ecs/registry.h"
#include <vector>

struct System {
  virtual void Update(Registry &registry) {}
  virtual void Render(Registry& registry) {}
};
