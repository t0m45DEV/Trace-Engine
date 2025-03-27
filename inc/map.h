#ifndef _H_MAP
#define _H_MAP

#include <GL/gl.h>
#include "trigonometry.h"

/** Maximum dimensions for a level */
#define MAX_MAP_SIZE 32 * 32

/** Size of the squares that forms the map, usually is good to have it (aprox) 3 times the player collision size */
#define MAP_CELL_SIZE  64

/** Returns the value in the middle of the square (you use first in one axis, then for the other) */
#define GRID_POS_TO_REAL_POS(X) ((X * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2.0))

/** Returns the index mapped from (X, Y) for map[] */
#define REAL_POS_TO_GRID_POS(X, Y) (((int) get_current_map_offset()) + ((int) (Y)) * ((int) get_current_map_dimensions().x) + ((int) (X)))

/**
 * Structures that can form the map
 */
typedef enum {
    UNDEFINED = -1, /** This structure is for error managing */
    AIR,            /** Nothing, the squares where the entities can move */
    STONE,
    WOOD,
    DOOR
} structures_t;

/**
 * Replaces the wall structure of the current map at the given position with the given new_wall
 */
void update_map_wall_at(const position_2D_t position, const structures_t new_wall);

/**
 * Returnss the wall structure of the current map at the given position
 */
structures_t get_map_wall_at(const position_2D_t position);

/**
 * Returnss the floor structure of the current map at the given position
 */
structures_t get_map_floor_at(const position_2D_t position);

/**
 * Returnss the ceiling structure of the current map at the given position
 */
structures_t get_map_ceiling_at(const position_2D_t position);

/**
 * Returns the level offset for the maps list, to get the map of that level
 * 
 * @param level_idx The index of the level to get (from 0 to LEVEL_COUNT)
 */
int get_map_offset_from_id(const int level_idx);

/**
 * Returns the map size of the level_idx level, in the form of
 * a position_2D_t, where x and y are the dimensions
 * 
 * @param level_idx The index of the level to get (from 0 to LEVEL_COUNT)
 */
position_2D_t get_map_size_from_id(const int level_idx);

/**
 * Returns the player spawn point of the level_idx level, in the form of
 * a position_2D_t
 * 
 * @param level_idx The index of the level to get (from 0 to LEVEL_COUNT)
 */
position_2D_t get_player_spwan_from_id(const int level_idx);

/**
 * Draw in the screen a 2D matrix of squares, white being wall and blakc being floor
 */
void draw_map_2D(void);


#define FIRST_LEVEL 1 /** Index of the level loaded when the game starts (0 <= index < LEVEL_COUNT) */
#define LEVEL_COUNT 2 /** Total number of levels */

#endif