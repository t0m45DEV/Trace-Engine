#ifndef _H_WIN_DISP
#define _H_WIN_DISP

#include <SDL.h>

#include "defines.h"

/** Fixed resolution levels */

typedef enum {
    LOW_RESOLUTION = 1,
    MID_RESOLUTION = 2,
    HIGH_RESOLUTION = 4
} resolutions_t;

/** Is good for the viewport size to satisfy WIDTH = HEIGHT * 1.5, and also for the numbers to be divisible by powers of 2 */

#define VIEWPORT_WIDTH  960
#define VIEWPORT_HEIGHT 640

#define VIEWPORT_X_OFFSET 10
#define VIEWPORT_Y_OFFSET 10

/** Color of the background (it's always block by the walls, anyway) */
#define BACKGROUND_COLOR (rgb_t) {0, 0, 0}

/**
 * Returns the current selected resolution
 */
int get_actual_resolution(void);

/**
 * Updates the current resolution to the given new one
 */
void set_actual_resolution(resolutions_t new_resolution);

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