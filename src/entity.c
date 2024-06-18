#include "entity.h"


entity_t calculate_offset(entity_t entity)
{
    if (entity.x_delta < 0)
    {
        entity.x_offset = (-1) * entity.collision_size;
    }
    else
    {
        entity.x_offset = entity.collision_size;
    }

    if (entity.y_delta < 0)
    {
        entity.y_offset = (-1) * entity.collision_size;
    }
    else
    {
        entity.y_offset = entity.collision_size;
    }

    return entity;
}


int is_colliding(entity_t entity, int col_pos)
{
    entity = calculate_offset(entity);

    int x_idx = entity.x_pos / (float) MAP_CELL_SIZE;
    int y_idx = entity.y_pos / (float) MAP_CELL_SIZE;

    int x_idx_add_offset = (entity.x_pos + entity.x_offset) / (float) MAP_CELL_SIZE;
    int y_idx_add_offset = (entity.y_pos + entity.y_offset) / (float) MAP_CELL_SIZE;

    int x_idx_sub_offset = (entity.x_pos - entity.x_offset) / (float) MAP_CELL_SIZE;
    int y_idx_sub_offset = (entity.y_pos - entity.y_offset) / (float) MAP_CELL_SIZE;

    if (col_pos == FRONT_RIGHT_COLLISION)
    {
        return (map[y_idx * MAP_X_SIZE + x_idx_add_offset] != AIR);
    }
    else if (col_pos == FRONT_LEFT_COLLISION)
    {
        return (map[y_idx_add_offset * MAP_X_SIZE + x_idx] != AIR);
    }
    else if (col_pos == BACK_RIGHT_COLLISION)
    {
        return (map[y_idx * MAP_X_SIZE + x_idx_sub_offset] != AIR);
    }
    else if (col_pos == BACK_LEFT_COLLISION)
    {
        return (map[y_idx_sub_offset * MAP_X_SIZE + x_idx] != AIR);
    }

    return NO_COLLISION;
}
