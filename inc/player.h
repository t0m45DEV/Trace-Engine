#ifndef _H_PLAYER
#define _H_PLAYER

#include "entity.h"

#define PI 3.1415926535

#define MOVE_VELOCITY    5
#define ROTATE_VELOCITY  0.1

#define P_INIT_X_POS  300.0
#define P_INIT_Y_POS  300.0


extern entity_t player;

/*
    Draw the player in the screen in the actual player position.

    The player is represented as a yellow dot with a line in front of him. This line represent the face of the player.
*/
void draw_player();

#endif