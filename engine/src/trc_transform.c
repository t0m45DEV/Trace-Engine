#include "trc_transform.h"

#include "trigonometry.h"
#include "map.h"

trc_world_position_t get_collision_axis(const trc_transform_t transform, const trc_world_position_t velocity)
{
    trc_world_position_t collision_border = normalize_vector(velocity);
    collision_border = scalar_multiplication(collision_border, transform.size);

    trc_world_position_t offset_in_x = (trc_world_position_t) {transform.pos.x + collision_border.x, transform.pos.y};
    trc_world_position_t offset_in_y = (trc_world_position_t) {transform.pos.x, transform.pos.y + collision_border.y};

    trc_world_position_t collision_axis = {
        get_map_wall_at(to_grid_pos(offset_in_x)) == AIR,
        get_map_wall_at(to_grid_pos(offset_in_y)) == AIR
    };
    return collision_axis;
}

void move_and_collide(trc_transform_t* transform, const trc_world_position_t velocity)
{
    trc_world_position_t direction = normalize_vector(velocity);
    direction = scalar_multiplication(direction, transform->size);

    trc_world_position_t offset;
    offset.x = transform->pos.x + direction.x;
    offset.y = transform->pos.y + direction.y;

    if (get_map_wall_at(to_grid_pos(offset)) == AIR)
    {
        transform->pos.x += velocity.x;
        transform->pos.y += velocity.y;
    }
}

void move_and_slide(trc_transform_t* transform, const trc_world_position_t velocity)
{
    trc_world_position_t collisions_axis = get_collision_axis(*transform, velocity);

    transform->pos.x += velocity.x * collisions_axis.x;
    transform->pos.y += velocity.y * collisions_axis.y;
}

void rotate_transform(trc_transform_t* transform, const float rotation_delta)
{
    transform->angle = adjust_angle(transform->angle + rotation_delta);
}
