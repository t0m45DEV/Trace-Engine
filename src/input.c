#include <GL/glut.h>

#include "input.h"
#include "player.h"


void buttons(unsigned char key, int x, int y)
{
    if (key == 'a') {player_x_pos -= 5;}
    if (key == 'd') {player_x_pos += 5;}
    if (key == 'w') {player_y_pos += 5;}
    if (key == 's') {player_y_pos -= 5;}

    glutPostRedisplay();
}
