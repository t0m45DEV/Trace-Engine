#ifndef _H_RENDER
#define _H_RENDER

#include "window_display.h"
#include "raycaster.h"
#include "map.h"

#define MAX_WALL_HEIGHT (WINDOW_HEIGHT / 2)
#define LINES_WIDTH ((int) (WINDOW_WIDTH / AMMOUNT_OF_RAYS))
#define CENTER_CORRECTION ((WINDOW_WIDTH / 2) - (LINES_WIDTH / 2))


/*
    Render a wall, off height (distance_from_player / MAX_WALL_HEIGHT) and draws it in the given ray position
*/
void render_line(float distance_from_player, int ray);

#endif