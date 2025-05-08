#ifndef _H_WIN_DISP
#define _H_WIN_DISP

#include <SDL.h>

#include "defines.h"
#include "trigonometry.h"

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

/**
 * Draw a point of the given size (plus the border) in the given position with the given color
 *
 * @note If you wan't a full square, pass a border of 0
 */
void draw_square(position_2D_t position, position_2D_t size, int border, rgb_t color);

/**
 * Draw a point of the given size in the given position with the given color
 */
void draw_point(position_2D_t position, int size, rgb_t color);

/**
 * Draw a line of the given thickness from the given start point to the given end point with the given color
 */
void draw_line(position_2D_t start_point, position_2D_t end_point, int thickness, rgb_t color);

#endif