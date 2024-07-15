#ifndef _H_RENDER
#define _H_RENDER

#include "window_display.h"
#include "raycaster.h"
#include "map.h"

#define MAX_WALL_HEIGHT (WINDOW_HEIGHT)                       /* A rename for WINDOW_HEIGHT, for easier code reading */
#define LINES_WIDTH ((int) (WINDOW_WIDTH / AMMOUNT_OF_RAYS))  /* Ammount of pixels each ray will draw on screen      */
#define X_CORRECTION (LINES_WIDTH / 2)                        /* Correction for X axis to get the screen centered    */
#define Y_CORRECTION (WINDOW_HEIGHT / 2)                      /* Correction for Y axis to get the screen centered    */

#define DISTANCE_CORRECTION (((float) WINDOW_WIDTH) / ((float) WINDOW_HEIGHT)) /* To see the walls square */

/*
    Calculates the color of the surface given the surface and a shade,
    it access the structures_colors[] array from map.h
*/
void set_wall_color(structures_t surface, float shade);

/*
    Render a wall, off height (distance_from_player / MAX_WALL_HEIGHT) and draws it in the given ray position
*/
void render_line(float distance_from_player, int ray);

#endif