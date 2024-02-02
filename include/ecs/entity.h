#pragma once

#include "component.h"

#include <vector>

/// Entity represents the unique id of given object in the game world.
static std::size_t entities = 0;

using Entity = std::size_t;

inline std::size_t NumberOfEntity() { return entities; }

inline Entity CreateEntity() {
  ++entities;
  return entities;
}
