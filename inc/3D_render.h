#ifndef _H_RENDER
#define _H_RENDER

#include "window_display.h"
#include "raycaster.h"
#include "map.h"

#define MAX_WALL_HEIGHT (WINDOW_HEIGHT)
#define LINES_WIDTH ((int) (WINDOW_WIDTH / AMMOUNT_OF_RAYS))
#define X_CORRECTION (LINES_WIDTH / 2)
#define Y_CORRECTION (WINDOW_HEIGHT / 2)

#define DISTANCE_CORRECTION (((float) WINDOW_WIDTH) / ((float) WINDOW_HEIGHT)) // To see the walls square

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