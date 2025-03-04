#include "player.h"

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
    player.pos.x = GRID_POS_TO_REAL_POS(get_current_player_spawn().x);
    player.pos.y = GRID_POS_TO_REAL_POS(get_current_player_spawn().y);
    player.angle = P_INIT_ANGLE;
    player.movement_velocity = MOVEMENT_VELOCITY;
    player.rotation_velocity = ROTATION_VELOCITY;
    player.delta.x = CALCULATE_X_DELTA(player.angle) * player.movement_velocity;
    player.delta.y = CALCULATE_Y_DELTA(player.angle) * player.movement_velocity;
    player.collision_size = P_COLLISION_SIZE;
    update_offset(&player);
}


void move_player(keys_state_t keys_state, float delta_time)
{
    update_offset(&player);

    if (keys_state.rotate_anti_clockwise)
    {
        player.angle -= player.rotation_velocity * delta_time;
        player.angle = adjust_angle(player.angle);
        
        player.delta.x = CALCULATE_X_DELTA(player.angle) * player.movement_velocity;
        player.delta.y = CALCULATE_Y_DELTA(player.angle) * player.movement_velocity;
    }
    if (keys_state.rotate_clockwise)
    {
        player.angle += player.rotation_velocity * delta_time;
        player.angle = adjust_angle(player.angle);

        player.delta.x = CALCULATE_X_DELTA(player.angle) * player.movement_velocity;
        player.delta.y = CALCULATE_Y_DELTA(player.angle) * player.movement_velocity;
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
    glColor3f(1, 1, 0);
    glPointSize(12);
    glBegin(GL_POINTS);
    glVertex2i(player.pos.x, player.pos.y);
    glEnd();

    float look_x_dir = player.pos.x + (player.delta.x / 5);
    float look_y_dir = player.pos.y + (player.delta.y / 5);

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(player.pos.x, player.pos.y);
    glVertex2i(look_x_dir, look_y_dir);
    glEnd();
}


void open_door(void)
{
    position_2D_t front_offset;
    front_offset.x = ((player.pos.x + player.offset.x) / (float) MAP_CELL_SIZE);
    front_offset.y = ((player.pos.y + player.offset.y) / (float) MAP_CELL_SIZE);

    /*
    int player_pos_grid = REAL_POS_TO_GRID_POS(player.pos.x / MAP_CELL_SIZE, player.pos.y / MAP_CELL_SIZE);
    int front_pos_grid = REAL_POS_TO_GRID_POS((player.pos.x / MAP_CELL_SIZE) + (player.offset.x / player.offset.x), (player.pos.y / MAP_CELL_SIZE) + (player.offset.y / player.offset.y));

    printf("Player block: %i\n", player_pos_grid);
    printf("Block in front: %i\n", front_pos_grid);
    */

    structures_t block_in_front = map_w[REAL_POS_TO_GRID_POS(front_offset.x, front_offset.y)];

    if (block_in_front == DOOR)
    {
        map_w[REAL_POS_TO_GRID_POS(front_offset.x, front_offset.y)] = AIR;
    }
}
