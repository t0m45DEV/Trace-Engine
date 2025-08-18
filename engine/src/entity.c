#include "entity.h"

#include "log.h"
#include "map.h"

#ifndef GAME_EXPORT
    #include <stdio.h>
    #include "trigonometry.h"

    char* entity_to_string_with_name(const entity_t entity, const char* entity_name)
    {
        const int MAX_LEN = 300;
        char* string = malloc(sizeof(char) * MAX_LEN);

        const char* entity_parsed =
            "\n\t=== Entity %s ===\n"
            "\t\t%s\n"
            "\t\t%s\n"
            "\t\tAngle: %f\n"
            "\t\tMovement velocity: %f\n"
            "\t\tRotation velocity: %f\n"
            "\t\tCollision size: %i\n"
            "\t\t%s\n"
        ;

        char* entity_pos    = trc_world_position_to_string_with_name(entity.pos, "Position");
        char* entity_delta  = trc_world_position_to_string_with_name(entity.delta, "Delta");
        char* entity_offset = trc_world_position_to_string_with_name(entity.offset, "Offset");

        int printf_out = snprintf(string, MAX_LEN, entity_parsed,
            entity_name,
            entity_pos,
            entity_delta,
            entity.angle,
            entity.movement_velocity,
            entity.rotation_velocity,
            entity.collision_size,
            entity_offset
        );

        if (printf_out <= 0)
        {
            log_error("There was an error parsing to string for %s", entity_name);
        }
        free(entity_pos);
        free(entity_delta);
        free(entity_offset);

        return string;
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


int can_move(const trc_grid_position_t idx, const trc_grid_position_t offset)
{
    int front  = get_map_wall_at((trc_grid_position_t) {offset.x, offset.y});
    int x_axis = get_map_wall_at((trc_grid_position_t) {offset.x, idx.y});
    int y_axis = get_map_wall_at((trc_grid_position_t) {idx.x, offset.y});

    /* Thing at idx don't have a wall directly on front
        and can slide in some axis X or Y */
    return !((front != AIR) && (x_axis == AIR) && (y_axis == AIR));
}


int is_colliding_in_axis(entity_t entity, const collision_directions_t axis)
{
    update_offset(&entity);

    trc_grid_position_t idx;
    idx = to_grid_pos(entity.pos);

    trc_grid_position_t add_offset;
    add_offset = to_grid_pos((trc_world_position_t) {entity.pos.x + entity.offset.x,
                                                        entity.pos.y + entity.offset.y});

    trc_grid_position_t sub_offset;
    sub_offset = to_grid_pos((trc_world_position_t) {entity.pos.x - entity.offset.x,
                                                        entity.pos.y - entity.offset.y});

    if (can_move(idx, add_offset)) /* If can move forward */
    {
        if (axis == FRONT_X_AXIS_COLLISION) /* If can slide forward along X axis */
        {
            return (get_map_wall_at((trc_grid_position_t) {add_offset.x, idx.y}) != AIR);
        }
        else if (axis == FRONT_Y_AXIS_COLLISION) /* If can slide forward along Y axis */
        {
            return (get_map_wall_at((trc_grid_position_t) {idx.x, add_offset.y}) != AIR);
        }
    }
    if (can_move(idx, sub_offset)) /* If can move backward */
    {
        if (axis == BACK_X_AXIS_COLLISION) /* If can slide backward along X axis */
        {
            return (get_map_wall_at((trc_grid_position_t) {sub_offset.x, idx.y}) != AIR);
        }
        else if (axis == BACK_Y_AXIS_COLLISION) /* If can slide backward along Y axis */
        {
            return (get_map_wall_at((trc_grid_position_t) {idx.x, sub_offset.y}) != AIR);
        }
    }
    return true; /* Entity can't move at any direction */
}
