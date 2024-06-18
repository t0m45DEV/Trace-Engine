#ifndef _H_MAP
#define _H_MAP

#include <GL/glut.h>

#define MAP_X_SIZE  16
#define MAP_Y_SIZE  8

#define MAP_CELL_SIZE  64

#define GRID_X_POS_TO_REAL_X_POS(X) ((X * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2))
#define GRID_Y_POS_TO_REAL_Y_POS(Y) ((Y * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2))

extern int map[];

extern enum structures_t {
    AIR,
    WALL
} structures;

/*
    Draw in the screen a 2D matrix of squares, white being wall and blakc being floor
*/
void draw_map_2D(void);

#endif