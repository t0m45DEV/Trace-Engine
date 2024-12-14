#ifndef _H_MAP
#define _H_MAP

#include <GL/gl.h>
#include "trigonometry.h"

/** Size of the squares that forms the map, usually is good to have it (aprox) 3 times the player collision size */
#define MAP_CELL_SIZE  64

/** Returns the size of the current map */
#define MAP_SIZE ((int) curr_lev_info.map_size.x * (int) curr_lev_info.map_size.y)

/** Returns the value in the middle of the square (you use first in one axis, then for the other) */
#define GRID_POS_TO_REAL_POS(X) ((X * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2))

/** Returns the index mapped from (X, Y) for map[] */
#define REAL_POS_TO_GRID_POS(X, Y) (((int) curr_lev_info.map_offset) + ((int) (Y)) * ((int) curr_lev_info.map_size.x) + ((int) (X)))

/**
 * Structures that can form the map
 */
typedef enum {
    AIR,  /**< Nothing, the squares where the entities can move */
    STONE,
    WOOD,
    DOOR
} structures_t;


/**
 * A color struct, having 3 variables: r, g and b
 */
typedef struct {
    float r; /**< Red component from RGB */
    float g; /**< Green component from RGB */
    float b; /**< Blue component from RGB */
} rgb_t;

extern structures_t map_w[];         /**< The wall maps for ALL the levels in one array */
extern structures_t map_f[];         /**< The floor maps for ALL the levels in one array */
extern structures_t map_c[];         /**< The ceiling maps for ALL the levels in one array */
extern position_2D_t maps_sizes[];     /**< The map sizes for each level */
extern position_2D_t player_spawns[];  /**< The player spawns for each level, saved in grid position style */

/**
 * Check if the given index is in range of the current level map
 *
 * @note curr_lev_info.mapp_offset <= idx < (curr_lev_info.mapp_offset + MAP_SIZE)
 */
int is_valid_map_index(int idx);

/**
 * Draw in the screen a 2D matrix of squares, white being wall and blakc being floor
 */
void draw_map_2D(void);


#define FIRST_LEVEL 1 /**< Index of the level loaded when the game starts (0 <= index < LEVEL_COUNT) */
#define LEVEL_COUNT 2 /**< Total number of levels */

/**
 * Holds all the info of a level
 */
typedef struct {
    int map_offset;           /**< Location in the maps array */
    position_2D_t map_size;     /**< Size of the map of the level, in the form of position_2D */
    position_2D_t player_spawn; /**< Location of the player when the level is loaded, in the form of position_2D */
} level_t;

extern level_t curr_lev_info; /**< Info of the current level  */
extern int current_level;     /**< Index of the current level */

#endif