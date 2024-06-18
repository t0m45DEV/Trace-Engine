#include "entity.h"


entity_t calculate_offset(entity_t entity)
{
    if (entity.x_delta < 0) {entity.x_offset = (-1) * entity.collision_size;}
    else {entity.x_offset = entity.collision_size;}

    if (entity.y_delta < 0) {entity.y_offset = (-1) * entity.collision_size;}
    else {entity.y_offset = entity.collision_size;}

    return entity;
}


int can_move(int x_idx, int y_idx, int x_idx_offset, int y_idx_offset)
{
    int front  = map[y_idx_offset * MAP_X_SIZE + x_idx_offset];
    int x_axis = map[y_idx * MAP_X_SIZE + x_idx_offset];
    int y_axis = map[y_idx_offset * MAP_X_SIZE + x_idx];

    return !((front != AIR) && (x_axis == AIR) && (y_axis == AIR));
}


int is_colliding_in_axis(entity_t entity, int axis)
{
    entity = calculate_offset(entity);

    int x_idx = entity.x_pos / (float) MAP_CELL_SIZE;
    int y_idx = entity.y_pos / (float) MAP_CELL_SIZE;

    int x_idx_add_offset = (entity.x_pos + entity.x_offset) / (float) MAP_CELL_SIZE;
    int y_idx_add_offset = (entity.y_pos + entity.y_offset) / (float) MAP_CELL_SIZE;

    int x_idx_sub_offset = (entity.x_pos - entity.x_offset) / (float) MAP_CELL_SIZE;
    int y_idx_sub_offset = (entity.y_pos - entity.y_offset) / (float) MAP_CELL_SIZE;

    if (axis == FRONT_X_AXIS_COLLISION)
    {
        if (can_move(x_idx, y_idx, x_idx_add_offset, y_idx_add_offset))
        {
            return (map[y_idx * MAP_X_SIZE + x_idx_add_offset] != AIR);
        }
        else {return true;}
    }
    else if (axis == FRONT_Y_AXIS_COLLISION)
    {
        if (can_move(x_idx, y_idx, x_idx_add_offset, y_idx_add_offset))
        {
            return (map[y_idx_add_offset * MAP_X_SIZE + x_idx] != AIR);
        }
        else {return true;}
    }
    else if (axis == BACK_X_AXIS_COLLISION)
    {
        if (can_move(x_idx, y_idx, x_idx_sub_offset, y_idx_sub_offset))
        {
            return (map[y_idx * MAP_X_SIZE + x_idx_sub_offset] != AIR);
        }
        else {return true;}
    }
    else if (axis == BACK_Y_AXIS_COLLISION)
    {
        if (can_move(x_idx, y_idx, x_idx_sub_offset, y_idx_sub_offset))
        {
            return (map[y_idx_sub_offset * MAP_X_SIZE + x_idx] != AIR);
        }
        else {return true;}
    }

    return NO_COLLISION;
}
