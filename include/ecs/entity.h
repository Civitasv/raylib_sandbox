#pragma once

#include "ecs/world.h"
#include "entt/entity/entity.hpp"
#include "entt/entity/fwd.hpp"
#include <cassert>
#include <utility>

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

  entt::entity entity_handle{entt::null};
  World *world = nullptr;
};