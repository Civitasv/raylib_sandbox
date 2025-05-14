#pragma once

#include "ecs/component.h"

struct KeyInputComponent: public Component {
  int key_down;

  KeyInputComponent() = default;
  KeyInputComponent(const KeyInputComponent&) = default;
};
