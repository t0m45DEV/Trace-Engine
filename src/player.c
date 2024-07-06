#include "player.h"

entity_t player = {0};

void reset_player_info(void)
{
    player.pos.x = GRID_POS_TO_REAL_POS(curr_lev_info.player_spawn.x);
    player.pos.y = GRID_POS_TO_REAL_POS(curr_lev_info.player_spawn.y);
    player.angle = P_INIT_ANGLE;
    player.velocity = MOVE_VELOCITY;
    player.delta.x = CALCULATE_X_DELTA(player.angle) * player.velocity;
    player.delta.y = CALCULATE_Y_DELTA(player.angle) * player.velocity;
    player.collision_size = P_COLLISION_SIZE;
    player = calculate_offset(player);
}


void draw_player(void)
{
    glColor3f(1, 1, 0);
    glPointSize(12);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glVertex2i(player.pos.x, player.pos.y);
    glEnd();

    float look_x_dir = player.pos.x + player.delta.x * MOVE_VELOCITY;
    float look_y_dir = player.pos.y + player.delta.y * MOVE_VELOCITY;

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(player.pos.x, player.pos.y);
    glVertex2i(look_x_dir, look_y_dir);
    glEnd();
}
