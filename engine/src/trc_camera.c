#include "trc_camera.h"

#include <math.h>

#include "log.h"
#include "textures.h"
#include "trigonometry.h"
#include "game_state.h"
#include "map.h"
#include "entity.h"
#include "graphics.h"

#define P_COLLISION_SIZE 20     /** Initial collision size for camera (check MAP_CELL_SIZE for size relation) */

#define MOVEMENT_VELOCITY  100    /** Initial camera movement velocity */
#define ROTATION_VELOCITY  2      /** Initial camera rotation velocity */

#define P_INIT_ANGLE 0          /** Initial camera vision angle (0 means bro is seeing right) */

#define P_COLOR COLOR_YELLOW /** The camera is yellow because reasons */

/** The camera info, like the position and actual direction of movement */
entity_t camera = {0};

position_2D_t get_camera_position(void)
{
    return camera.pos;
}

void set_camera_position(position_2D_t new_pos)
{
    camera.pos = new_pos;
}

float get_camera_angle(void)
{
    return camera.angle;
}

void reset_camera_info(void)
{
    camera.pos = map_pos_to_real_pos(get_current_player_spawn());
    camera.angle = P_INIT_ANGLE;
    camera.movement_velocity = MOVEMENT_VELOCITY;
    camera.rotation_velocity = ROTATION_VELOCITY;
    camera.delta.x = cos(camera.angle) * camera.movement_velocity;
    camera.delta.y = sin(camera.angle) * camera.movement_velocity;
    camera.collision_size = P_COLLISION_SIZE;
    update_offset(&camera);

    log_info("camera info reseted.");
}


void move_camera(keys_state_t keys_state, float delta_time)
{
    update_offset(&camera);

    if (keys_state.rotate_anti_clockwise)
    {
        camera.angle -= camera.rotation_velocity * delta_time;
        camera.angle = adjust_angle(camera.angle);
        
        camera.delta.x = cos(camera.angle) * camera.movement_velocity;
        camera.delta.y = sin(camera.angle) * camera.movement_velocity;
    }
    if (keys_state.rotate_clockwise)
    {
        camera.angle += camera.rotation_velocity * delta_time;
        camera.angle = adjust_angle(camera.angle);

        camera.delta.x = cos(camera.angle) * camera.movement_velocity;
        camera.delta.y = sin(camera.angle) * camera.movement_velocity;
    }
    if (keys_state.move_forward)
    {
        //if (!is_colliding_in_axis(camera, FRONT_X_AXIS_COLLISION)) camera.pos.x += camera.delta.x * delta_time;
        //if (!is_colliding_in_axis(camera, FRONT_Y_AXIS_COLLISION)) camera.pos.y += camera.delta.y * delta_time;
    }
    if (keys_state.move_backward)
    {
        if (!is_colliding_in_axis(camera, BACK_X_AXIS_COLLISION)) camera.pos.x -= camera.delta.x * delta_time;
        if (!is_colliding_in_axis(camera, BACK_Y_AXIS_COLLISION)) camera.pos.y -= camera.delta.y * delta_time;
    }
}


void draw_camera(void)
{
    draw_point(camera.pos, 12, P_COLOR);

    float look_x_dir = camera.pos.x + (camera.delta.x / 5);
    float look_y_dir = camera.pos.y + (camera.delta.y / 5);
    position_2D_t look_dir = (position_2D_t) {look_x_dir, look_y_dir};

    draw_line(camera.pos, look_dir, 4, P_COLOR);
}


void open_door(void)
{
    position_2D_t front_offset;
    front_offset.x = ((camera.pos.x + camera.offset.x) / (float) MAP_CELL_SIZE);
    front_offset.y = ((camera.pos.y + camera.offset.y) / (float) MAP_CELL_SIZE);

    structures_t block_in_front = get_map_wall_at((position_2D_t) {front_offset.x, front_offset.y});

    if (block_in_front == DOOR)
    {
        update_map_wall_at((position_2D_t) {front_offset.x, front_offset.y}, AIR);
    }
}
