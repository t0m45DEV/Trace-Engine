#ifndef _H_WIN_DISP
#define _H_WIN_DISP

#include <SDL.h>

#include "raycaster.h"
#include "player.h"
#include "input.h"
#include "map.h"

/** Fixed resolution levels */

#define HIGH_RESOLUTION 4
#define MID_RESOLUTION 2
#define LOW_RESOLUTION 1

/** The current resolution of the game, more resolution means more rays, so a big value could compromise performance, use fixed values */
extern int resolution;

/** To draw the top-down 2D view of the levels, only for debug, or maybe make a map for the player */
extern bool debug_2D_view;

#define WINDOW_TITLE "Tom's 3D Engine"

/** Is good for the window size to satisfy WIDTH = HEIGHT * 1.5, and also for the numbers to be divisible by powers of 2 */

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640

/** V-sync modes */

#define V_SYNC_OFF    0  /**< Immediate update from frame to frame */
#define V_SYNC_ON     1  /**< Updates synchronized with the vertical retrace */
#define V_SYNC_ADAPT -1  /**< Adaptive V-sync */

extern int fps;     /**< Frame per second counter */

extern float delta_time;   /**< The time elapsed between last frame and the actual one */


/** Color of the background (it's always block by the walls, anyway) */
#define BACKGROUND_COLOR (rgb_t) {0, 0, 0}

/**
 * Creates the window and the context for OpenGL
 * 
 * @param title The title of the window, it'll show up in the upper section of the window
 * @param width The window width in pixels
 * @param height The window height in pixels
 */
SDL_Window* create_window(const char* title, const int width, const int height);

/**
 * Change the color of the screen when called glClear()
 * 
 * @param color The color to change to
 */
void set_background_color(const rgb_t color);

/**
 * Draw the objects in the window
 */
void render_screen(void);

#endif