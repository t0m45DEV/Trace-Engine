#ifndef _H_PLAYER
#define _H_PLAYER

#include <GL/glut.h>

#include "entity.h"

#define P_COLLISION_SIZE 20

#define MOVE_VELOCITY    3
#define ROTATE_VELOCITY  0.08

#define P_INIT_ANGLE 0

// The player info, like the position and actual direction of movement
extern entity_t player;

/*
    Sets the player info to the current level 
    
    If you change or reset the level, call this function to update the player position, velocity, etc
*/
void reset_player_info(void);

/*
    Draw the player in the screen in the actual player position.

    The player is represented as a yellow dot with a line in front of him. This line represent the face of the player.
*/
void draw_player(void);

#endif