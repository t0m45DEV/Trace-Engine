#include "player.h"

entity_t player = 
{
    .pos.x    = P_INIT_X_POS,
    .pos.y    =  P_INIT_Y_POS,
    .delta.x  = MOVE_VELOCITY, // CALCULATE_X_DELTA(player.angle)
    .delta.y  = 0,             // CALCULATE_Y_DELTA(player.angle)
    .angle    = 0,
    .velocity = MOVE_VELOCITY,
    .collision_size = P_COLLISION_SIZE,
    .offset.x = 0,
    .offset.y = 0
};

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
