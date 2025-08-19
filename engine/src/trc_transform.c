#include "trc_transform.h"

#include "trigonometry.h"
#include "map.h"

#include "log.h"

void move_and_slide(trc_transform_t* transform, const trc_world_position_t velocity)
{
    trc_world_position_t direction = normalize_vector(velocity);
    direction = scalar_multiplication(direction, transform->size);

    trc_world_position_t offset;
    offset.x = transform->pos.x + direction.x;
    offset.y = transform->pos.y + direction.y;

    if (get_map_wall_at(to_grid_pos(offset)) != AIR)
    {
        log_info("Collision detected!");
    }
    else
    {
        transform->pos.x += velocity.x;
        transform->pos.y += velocity.y;
    }
}

void rotate_transform(trc_transform_t* transform, const float rotation_delta)
{
    transform->angle = adjust_angle(transform->angle + rotation_delta);
}
