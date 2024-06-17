#include "entity.h"


entity_t calculate_offset(entity_t entity)
{
    if (entity.x_delta < 0)
    {
        entity.x_offset = -entity.collision_size;
    }
    else
    {
        entity.x_offset = entity.collision_size;
    }

    if (entity.y_delta < 0)
    {
        entity.y_offset = -entity.collision_size;
    }
    else
    {
        entity.y_offset = entity.collision_size;
    }

    return entity;
}
