#ifndef _H_WIN_DISP
#define _H_WIN_DISP

#include <GL/glut.h>

#include "raycaster.h"
#include "player.h"
#include "input.h"
#include "map.h"

#define HIGH_RESOLUTION 4
#define MID_RESOLUTION 2
#define LOW_RESOLUTION 1

extern int resolution;

extern bool debug_2D_view;

#define WINDOW_TITLE "Tom's 3D Engine"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 512

#define X_CENTER_POS ((glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2)
#define Y_CENTER_POS ((glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2)


#define MAX_FPS 60

extern float fps;

#define FPS_CORRECTION (0.02 * fps)


/*
    Update fps by substracting the actual frame from the previous
*/
void update_fps(void);


/*
    Draw the objects in the window
*/
void display(void);


/*
    Resize the window to the fixed value WINDOW_WIDTH x WINDOW_HEIGHT
*/
void resize(int x, int y);


/*
    Creates the windows and manage mainLoop

    @param argc Number of arguments
    @param argv Vector of arguments
*/
void window_create(int argc, char** argv);

#endif