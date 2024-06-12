#include <GL/glut.h>

#include <player.h>
#include "defines.h"


void draw_player(float x_pos, float y_pos)
{
    glColor3f(1, 0, 0);
    glPointSize(12);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glVertex2i(x_pos, y_pos);
    glEnd();
}
