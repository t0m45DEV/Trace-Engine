#ifndef _H_GRAPHICS
#define _H_GRAPHICS

#include "trigonometry.h"

/**
 * A color struct, having 3 variables: r, g and b; each one an int from 0 to 255
 */
typedef struct {
    unsigned char r; /** Red component from RGB */
    unsigned char g; /** Green component from RGB */
    unsigned char b; /** Blue component from RGB */
} rgb_t;

// A few colors, useful for testing or drawing directly

#define COLOR_BLACK    (rgb_t) {  0,   0, 0  }
#define COLOR_BLUE     (rgb_t) {  0,   0, 255}
#define COLOR_GREEN    (rgb_t) {  0, 255, 0  }
#define COLOR_CYAN     (rgb_t) {  0, 255, 255}
#define COLOR_RED      (rgb_t) {255,   0, 0  }
#define COLOR_MAGENTA  (rgb_t) {255,   0, 255}
#define COLOR_YELLOW   (rgb_t) {255, 255, 0  }
#define COLOR_WHITE    (rgb_t) {255, 255, 255}

/** Color of the background (it's always block by the walls, anyway) */
#define BACKGROUND_COLOR COLOR_BLACK

/** Fixed resolution levels */

typedef enum {
    LOW_RESOLUTION = 1,
    MID_RESOLUTION = 2,
    HIGH_RESOLUTION = 4
} resolutions_t;

/**
 * Returns the current selected resolution
 */
int get_actual_resolution(void);

/**
 * Updates the current resolution to the given new one
 */
void set_actual_resolution(resolutions_t new_resolution);

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