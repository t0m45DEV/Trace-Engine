#include <GL/glut.h>

#include "windowDisplay.h"
#include "defines.h"
#include "player.h"


void display_me(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_player(P_INIT_X_POS, P_INIT_Y_POS);
    glutSwapBuffers();
}


/*
    Creates the windows and manage mainLoop. The size, position and title are defined in the defines.h file.

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
    glClearColor(0.5, 0.7, 0.5, 0);
    glutDisplayFunc(display_me);
    glutMainLoop();
}
