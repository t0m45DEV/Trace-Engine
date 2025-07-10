#ifndef _H_MAP
#define _H_MAP

#include "glad/glad.h"
#include "trigonometry.h"

/** Size of the squares that forms the map, usually is good to have it (aprox) 3 times the player collision size */
#define MAP_CELL_SIZE  64

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
 * Returns the windows position for the middle of the map square
 */
position_2D_t map_pos_to_real_pos(position_2D_t map_pos);

/**
 * Updates the current map info to the map of the level_idx level
 */
void change_to_map(int level_idx);

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