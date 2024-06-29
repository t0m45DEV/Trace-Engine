#ifndef _H_MAP
#define _H_MAP

#include <GL/glut.h>
#include "trigonometry.h"
#include "world.h"

#define MAP_CELL_SIZE  64

#define MAP_SIZE ((int) curr_lev_info.map_size.x * (int) curr_lev_info.map_size.y)

#define GRID_X_POS_TO_REAL_X_POS(X) ((X * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2))
#define GRID_Y_POS_TO_REAL_Y_POS(Y) ((Y * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2))

#define REAL_POS_TO_GRID_POS(X, Y) (((int) curr_lev_info.map_offset) + ((int) (Y)) * ((int) curr_lev_info.map_size.x) + ((int) (X)))

typedef enum structures_s {
    AIR,
    WALL
} structures_t;

extern structures_t map[];
extern position_2D maps_sizes[LEVEL_COUNT];
extern position_2D player_spawns[LEVEL_COUNT];

/*
    Check if the given index is in range of the current level map

    curr_lev_info.mapp_offset <= idx < (curr_lev_info.mapp_offset + MAP_SIZE)
*/
int is_valid_map_index(int idx);

/*
    Draw in the screen a 2D matrix of squares, white being wall and blakc being floor
*/
void draw_map_2D(void);

#endif