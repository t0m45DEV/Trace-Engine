#ifndef _H_WIN_DISP
#define _H_WIN_DISP

#include <GL/glut.h>

#include "raycaster.h"
#include "player.h"
#include "input.h"
#include "map.h"

#define DEBUG_2D_VIEW true

#define WINDOW_TITLE "Scape game"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 512

#define X_CENTER_POS ((glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2)
#define Y_CENTER_POS ((glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2)

/*
    Draw the objects in the window
*/
void display(void);


/*
    Creates the windows and manage mainLoop

    @param argc Number of arguments
    @param argv Vector of arguments
*/
void window_create(int argc, char** argv);

#endif