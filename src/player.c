#include "player.h"

entity_t player = 
{
    .x_pos    = P_INIT_X_POS,
    .y_pos    =  P_INIT_Y_POS,
    .x_delta  = MOVE_VELOCITY, // CALCULATE_X_DELTA(player.angle)
    .y_delta  = 0,             // CALCULATE_Y_DELTA(player.angle)
    .angle    = 0,
    .velocity = MOVE_VELOCITY,
    .collision_size = P_COLLISION_SIZE,
    .x_offset = 0,
    .y_offset = 0
};

void draw_player(void)
{
    glColor3f(1, 1, 0);
    glPointSize(12);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glVertex2i(player.x_pos, player.y_pos);
    glEnd();

    float look_x_dir = player.x_pos + player.x_delta * MOVE_VELOCITY;
    float look_y_dir = player.y_pos + player.y_delta * MOVE_VELOCITY;

    player = calculate_offset(player);

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(player.x_pos, player.y_pos);
    glVertex2i(look_x_dir, look_y_dir);
    glEnd();
}
