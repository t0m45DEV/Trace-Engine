#include <GL/glut.h>

#include <player.h>
#include "defines.h"


#define P_INIT_X_POS 300.0
#define P_INIT_Y_POS 300.0

float player_x_pos = P_INIT_X_POS;
float player_y_pos = P_INIT_Y_POS;


void draw_player(float x_pos, float y_pos)
{
    player_x_pos = x_pos;
    player_y_pos = y_pos;

    glColor3f(1, 0, 0);
    glPointSize(12);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glVertex2i(player_x_pos, player_y_pos);
    glEnd();
}
