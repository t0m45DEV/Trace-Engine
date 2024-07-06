#ifndef _H_WIN_DISP
#define _H_WIN_DISP

#include <GL/glut.h>

#include "raycaster.h"
#include "player.h"
#include "input.h"
#include "map.h"

// Fixed resolution levels

#define HIGH_RESOLUTION 4
#define MID_RESOLUTION 2
#define LOW_RESOLUTION 1

// The current resolution of the game, more resolution means more rays, so a big value could compromise performance, use fixed values
extern int resolution;

// To draw the top-down 2D view of the levels, only for debug, or maybe make a map for the player
extern bool debug_2D_view;

#define WINDOW_TITLE "Tom's 3D Engine"



// Is good for the window size to satisfy WIDTH = HEIGHT * 1.5, and also for the numbers to be divisible by powers of 2

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640

#define X_CENTER_POS ((glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2)    // To center the window in relation with the screen X axis
#define Y_CENTER_POS ((glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2)  // To center the window in relation with the screen Y axis


#define MAX_FPS 60  // It is what it says

extern float fps;   // Current FPS, never should exceeds MAX_FPS

#define FPS_CORRECTION (0.03 * fps) // A time correction, this could change in relation of player stats


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