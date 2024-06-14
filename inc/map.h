#ifndef _H_MAP
#define _H_MAP

#define MAP_X_SIZE  8
#define MAP_Y_SIZE  8

#define MAP_CELL_SIZE  64

extern int map[];


/*
    Draw in the screen a 2D matrix of squares, white being wall and blakc being floor
*/
void draw_map_2D(void);

#endif