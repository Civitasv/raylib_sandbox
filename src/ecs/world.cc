#include "ecs/world.h"
#include "ecs/entity.h"

Entity World::CreateEntity() { return {registry.create(), this}; }

void World::DestroyEntity(Entity &entity) {
  entity.destroy();
}
