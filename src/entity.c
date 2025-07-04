#include "entity.h"

#include "log.h"
#include "map.h"

#ifndef GAME_EXPORT
    void print_entity(const entity_t entity, const char* entity_name)
    {
        const char* entity_parsed =
            "\n\t=== Entity %s ===\n"
            "\t\tPosition: (%f, %f)\n"
            "\t\tDelta: (%f, %f)\n"
            "\t\tAngle: %f\n"
            "\t\tMovement velocity: %f\n"
            "\t\tRotation velocity: %f\n"
            "\t\tCollision size: %i\n"
            "\t\tOffset: (%f, %f)\n"
        ;

        log_debug(entity_parsed,
            entity_name,
            entity.pos.x, entity.pos.y,
            entity.delta.x, entity.delta.y,
            entity.angle,
            entity.movement_velocity,
            entity.rotation_velocity,
            entity.collision_size,
            entity.offset.x, entity.offset.y
        );
    }
#endif

void update_offset(entity_t* entity)
{
    if (entity->delta.x < 0)
    {
        entity->offset.x = (-1) * entity->collision_size;
    }
    else
    {
        entity->offset.x = entity->collision_size;
    }

    if (entity->delta.y < 0)
    {
        entity->offset.y = (-1) * entity->collision_size;
    }
    else
    {
        entity->offset.y = entity->collision_size;
    }
}


int can_move(const position_2D_t idx, const position_2D_t offset)
{
    int front  = get_map_wall_at((position_2D_t) {offset.x, offset.y});
    int x_axis = get_map_wall_at((position_2D_t) {offset.x, idx.y});
    int y_axis = get_map_wall_at((position_2D_t) {idx.x, offset.y});

    /* Thing at idx don't have a wall directly on front
        and can slide in some axis X or Y */
    return !((front != AIR) && (x_axis == AIR) && (y_axis == AIR));
}


int is_colliding_in_axis(entity_t entity, const collision_directions_t axis)
{
    update_offset(&entity);

    position_2D_t idx;
    idx.x = entity.pos.x / (float) MAP_CELL_SIZE;
    idx.y = entity.pos.y / (float) MAP_CELL_SIZE;

    position_2D_t add_offset;
    add_offset.x = (entity.pos.x + entity.offset.x) / (float) MAP_CELL_SIZE;
    add_offset.y = (entity.pos.y + entity.offset.y) / (float) MAP_CELL_SIZE;

    position_2D_t sub_offset;
    sub_offset.x = (entity.pos.x - entity.offset.x) / (float) MAP_CELL_SIZE;
    sub_offset.y = (entity.pos.y - entity.offset.y) / (float) MAP_CELL_SIZE;

    if (can_move(idx, add_offset)) /* If can move forward */
    {
        if (axis == FRONT_X_AXIS_COLLISION) /* If can slide forward along X axis */
        {
            return (get_map_wall_at((position_2D_t) {add_offset.x, idx.y}) != AIR);
        }
        else if (axis == FRONT_Y_AXIS_COLLISION) /* If can slide forward along Y axis */
        {
            return (get_map_wall_at((position_2D_t) {idx.x, add_offset.y}) != AIR);
        }
    }
    if (can_move(idx, sub_offset)) /* If can move backward */
    {
        if (axis == BACK_X_AXIS_COLLISION) /* If can slide backward along X axis */
        {
            return (get_map_wall_at((position_2D_t) {sub_offset.x, idx.y}) != AIR);
        }
        else if (axis == BACK_Y_AXIS_COLLISION) /* If can slide backward along Y axis */
        {
            return (get_map_wall_at((position_2D_t) {idx.x, sub_offset.y}) != AIR);
        }
    }
    return true; /* Entity can't move at any direction */
}
