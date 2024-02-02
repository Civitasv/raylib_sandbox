#pragma once

#include "ecs/components/keyinput.h"
#include "ecs/components/sprite.h"
#include "ecs/components/transform.h"
#include "ecs/entity.h"
#include <unordered_map>

struct Registry {
  std::unordered_map<Entity, SpriteComponent> sprites;
  std::unordered_map<Entity, TransformComponent> transforms;
  std::unordered_map<Entity, KeyInputComponent> keys;
};
