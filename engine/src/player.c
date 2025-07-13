#include "player.h"

#include <math.h>

#include "log.h"
#include "textures.h"
#include "trigonometry.h"
#include "game_state.h"
#include "map.h"
#include "entity.h"
#include "window_manager.h"

#define P_COLLISION_SIZE 20     /** Initial collision size for player (check MAP_CELL_SIZE for size relation) */

#define MOVEMENT_VELOCITY  100    /** Initial player movement velocity */
#define ROTATION_VELOCITY  2      /** Initial player rotation velocity */

#define P_INIT_ANGLE 0          /** Initial player vision angle (0 means bro is seeing right) */

#define P_COLOR (rgb_t) {255, 255, 0} /** The player is yellow because reasons */

/** The player info, like the position and actual direction of movement */
entity_t player = {0};

position_2D_t get_player_position(void)
{
    return player.pos;
}

angle_t get_player_angle(void)
{
    return player.angle;
}

void reset_player_info(void)
{
    player.pos = map_pos_to_real_pos(get_current_player_spawn());
    player.angle = P_INIT_ANGLE;
    player.movement_velocity = MOVEMENT_VELOCITY;
    player.rotation_velocity = ROTATION_VELOCITY;
    player.delta.x = cos(player.angle) * player.movement_velocity;
    player.delta.y = sin(player.angle) * player.movement_velocity;
    player.collision_size = P_COLLISION_SIZE;
    update_offset(&player);

    log_info("Player info reseted.");
}


void move_player(keys_state_t keys_state, float delta_time)
{
    update_offset(&player);

    if (keys_state.rotate_anti_clockwise)
    {
        player.angle -= player.rotation_velocity * delta_time;
        player.angle = adjust_angle(player.angle);
        
        player.delta.x = cos(player.angle) * player.movement_velocity;
        player.delta.y = sin(player.angle) * player.movement_velocity;
    }
    if (keys_state.rotate_clockwise)
    {
        player.angle += player.rotation_velocity * delta_time;
        player.angle = adjust_angle(player.angle);

        player.delta.x = cos(player.angle) * player.movement_velocity;
        player.delta.y = sin(player.angle) * player.movement_velocity;
    }
    if (keys_state.move_forward)
    {
        if (!is_colliding_in_axis(player, FRONT_X_AXIS_COLLISION)) player.pos.x += player.delta.x * delta_time;
        if (!is_colliding_in_axis(player, FRONT_Y_AXIS_COLLISION)) player.pos.y += player.delta.y * delta_time;
    }
    if (keys_state.move_backward)
    {
        if (!is_colliding_in_axis(player, BACK_X_AXIS_COLLISION)) player.pos.x -= player.delta.x * delta_time;
        if (!is_colliding_in_axis(player, BACK_Y_AXIS_COLLISION)) player.pos.y -= player.delta.y * delta_time;
    }
}


void draw_player(void)
{
    draw_point(player.pos, 12, P_COLOR);

    float look_x_dir = player.pos.x + (player.delta.x / 5);
    float look_y_dir = player.pos.y + (player.delta.y / 5);
    position_2D_t look_dir = (position_2D_t) {look_x_dir, look_y_dir};

    draw_line(player.pos, look_dir, 4, P_COLOR);
}


void open_door(void)
{
    position_2D_t front_offset;
    front_offset.x = ((player.pos.x + player.offset.x) / (float) MAP_CELL_SIZE);
    front_offset.y = ((player.pos.y + player.offset.y) / (float) MAP_CELL_SIZE);

    structures_t block_in_front = get_map_wall_at((position_2D_t) {front_offset.x, front_offset.y});

    if (block_in_front == DOOR)
    {
        update_map_wall_at((position_2D_t) {front_offset.x, front_offset.y}, AIR);
    }
}
