#include "player.h"

entity_t player = 
{
    P_INIT_X_POS,  // player.x_pos
    P_INIT_Y_POS,  // player.y_pos
    MOVE_VELOCITY, // player.x_delta = CALCULATE_X_DELTA(player.angle)
    0,             // player.y_delta = CALCULATE_Y_DELTA(player.angle)
    0,             // player.angle
    MOVE_VELOCITY  // player.velocity
};


void draw_player()
{
    glColor3f(1, 1, 0);
    glPointSize(12);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glVertex2i(player.x_pos, player.y_pos);
    glEnd();

    float look_x_dir = player.x_pos + player.x_delta * MOVE_VELOCITY;
    float look_y_dir = player.y_pos + player.y_delta * MOVE_VELOCITY;

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(player.x_pos, player.y_pos);
    glVertex2i(look_x_dir, look_y_dir);
    glEnd();
}
