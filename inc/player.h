#ifndef _H_PLAYER
#define _H_PLAYER

#include <GL/glut.h>

#include "entity.h"
#include "map.h"

#define P_COLLISION_SIZE 20

#define MOVE_VELOCITY    2
#define ROTATE_VELOCITY  0.08

#define P_X_SPAWN 1
#define P_Y_SPAWN 6

#define P_INIT_X_POS  GRID_X_POS_TO_REAL_X_POS(P_X_SPAWN)
#define P_INIT_Y_POS  GRID_Y_POS_TO_REAL_Y_POS(P_Y_SPAWN)


extern entity_t player; // The player info, like the position and angle of vision

/*
    Draw the player in the screen in the actual player position.

    The player is represented as a yellow dot with a line in front of him. This line represent the face of the player.
*/
void draw_player(void);

#endif