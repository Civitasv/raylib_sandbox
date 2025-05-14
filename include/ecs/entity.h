#pragma once

#include "ecs/world.h"
#include "entt/entity/entity.hpp"
#include "entt/entity/fwd.hpp"
#include <cassert>
#include <utility>

/// Entity is just an identifier.
/// It has Multi Components.
struct Entity {
  template <typename T, typename... Args> T &AddComponent(Args... args) {
    // TODO It's an error!
    assert(!HasComponent<T>());

    T &component =
        world->registry.emplace<T>(entity_handle, std::forward<Args>(args)...);

    return component;
  }

  template <typename T> bool HasComponent() {
    return world->registry.all_of<T>(entity_handle);
  }

  ~Entity() {
    std::cout << "Release Entity" << std::endl;
    destroy();
  }

  void destroy() {
    if (!world) {
      return;
    }
    if (world->registry.valid(entity_handle)) {
      world->registry.destroy(entity_handle);
      entity_handle = entt::null;
    }
  }

  entt::entity entity_handle{entt::null};
  World *world = nullptr;
};
