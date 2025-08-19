#ifndef _H_MAP
#define _H_MAP

#include "trc_world_position.h"

/** Size of the squares that forms the map, usually is good to have it (aprox) 3 times the player collision size */
#define MAP_CELL_SIZE  64

/**
 * A vector of 2 dimensions, the values x and y are floats
 * 
 * Useful for accesing the map cells
 */
typedef struct {
    int x;
    int y;
} trc_grid_position_t;

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
 * Given a position in a grid (with integers) returns the trc_grid_position_t with
 * the values pointing to the same cell in the map (in the center of the
 * cell, to be precise)
 */
trc_world_position_t to_world_pos(trc_grid_position_t grid_pos);

/**
 * Given a trc_grid_position_t (with floats) returns the corresponding cell
 * position in the current map
 */
trc_grid_position_t to_grid_pos(trc_world_position_t world_pos);

/**
 * Returns the windows position for the middle of the map square
 */
trc_world_position_t map_pos_to_real_pos(const trc_world_position_t map_pos);

/**
 * Updates the current map info to the map of the level_idx level
 */
void change_to_map(int level_idx);

/**
 * Replaces the wall structure of the current map at the given position with the given new_wall
 */
void update_map_wall_at(const trc_grid_position_t position, const structures_t new_wall);

/**
 * Returns the wall structure of the current map at the given position
 */
structures_t get_map_wall_at(const trc_grid_position_t position);

/**
 * Returnss the floor structure of the current map at the given position
 */
structures_t get_map_floor_at(const trc_grid_position_t position);

/**
 * Returnss the ceiling structure of the current map at the given position
 */
structures_t get_map_ceiling_at(const trc_grid_position_t position);

/**
 * Returns the level offset for the maps list, to get the map of that level
 * 
 * @param level_idx The index of the level to get (from 0 to LEVEL_COUNT)
 */
int get_map_offset_from_id(const int level_idx);

/**
 * Returns the map size of the level_idx level, in the form of
 * a trc_world_position_t, where x and y are the dimensions
 * 
 * @param level_idx The index of the level to get (from 0 to LEVEL_COUNT)
 */
trc_world_position_t get_map_size_from_id(const int level_idx);

/**
 * Returns the player spawn point of the level_idx level, in the form of
 * a trc_world_position_t
 * 
 * @param level_idx The index of the level to get (from 0 to LEVEL_COUNT)
 */
trc_world_position_t get_camera_spwan_from_id(const int level_idx);

/**
 * Draw in the screen a 2D matrix of squares, white being wall and blakc being floor
 */
void draw_map_2D(void);


#define FIRST_LEVEL 1 /** Index of the level loaded when the game starts (0 <= index < LEVEL_COUNT) */
#define LEVEL_COUNT 2 /** Total number of levels */

#endif