#include <GL/glut.h>

#include "windowDisplay.h"
#include "player.h"
#include "input.h"
#include "map.h"


/*
    Draw the objects in the window
*/
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_map_2D();
    draw_player(player_x_pos, player_y_pos);
    glutSwapBuffers();
}


/*
    Creates the windows and manage mainLoop. The size, position and title are defined in the windowDisplay.h file.

    @param argc Number of arguments
    @param argv Vector of arguments
*/
void window_create(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(X_CENTER_POS, Y_CENTER_POS);
    glutCreateWindow(WINDOW_TITLE);
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glClearColor(0.5, 0.5, 0.5, 0);
    glutDisplayFunc(display);
    glutKeyboardFunc(buttons);
    glutMainLoop();
}
