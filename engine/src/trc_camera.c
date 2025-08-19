#include "trc_camera.h"

#include <math.h>

#include "log.h"
#include "game_state.h"
#include "map.h"
#include "graphics.h"
#include "trc_transform.h"

/** Initial collision size for camera (check MAP_CELL_SIZE for size relation) */
#define CAM_DEFAULT_COLLISION_SIZE 20

/** Initial camera vision angle (0 means bro is seeing right) */
#define CAM_DEFAULT_INIT_ANGLE 0

/** The camera is yellow because reasons */
#define P_COLOR COLOR_YELLOW

/** The camera info, like the position and actual direction of movement */
trc_transform_t trc_camera;

trc_world_position_t get_camera_position(void)
{
    return trc_camera.pos;
}

float get_camera_angle(void)
{
    return trc_camera.angle;
}

trc_world_position_t get_camera_direction(void)
{
    trc_world_position_t direction;
    direction.x = cos(trc_camera.angle);
    direction.y = sin(trc_camera.angle);

    return direction;
}

void set_camera_position(const trc_world_position_t velocity)
{
    move_and_slide(&trc_camera, velocity);
}

void rotate_camera(const float rotation_delta)
{
    rotate_transform(&trc_camera, rotation_delta);
}

void reset_camera_info(void)
{
    trc_camera.pos = map_pos_to_real_pos(get_current_camera_spawn());
    trc_camera.angle = CAM_DEFAULT_INIT_ANGLE;
    trc_camera.size = CAM_DEFAULT_COLLISION_SIZE;

    log_info("camera info reseted.");
}

void draw_camera(void)
{
    draw_point(trc_camera.pos, 12, P_COLOR);

    float look_x_dir = trc_camera.pos.x + (cos(trc_camera.angle) * trc_camera.size);
    float look_y_dir = trc_camera.pos.y + (sin(trc_camera.angle) * trc_camera.size);
    trc_world_position_t look_dir = (trc_world_position_t) {look_x_dir, look_y_dir};

    draw_line(trc_camera.pos, look_dir, 4, P_COLOR);
}


void open_door(void)
{
    /*
    trc_world_position_t front_offset;
    front_offset.x = ((camera.pos.x + camera.offset.x) / (float) MAP_CELL_SIZE);
    front_offset.y = ((camera.pos.y + camera.offset.y) / (float) MAP_CELL_SIZE);

    structures_t block_in_front; //= get_map_wall_at((trc_world_position_t) {front_offset.x, front_offset.y});

    if (block_in_front == DOOR)
    {
        update_map_wall_at((trc_grid_position_t) {front_offset.x, front_offset.y}, AIR);
    }
    */
}
