#ifndef _H_WORLD
#define _H_WORLD

#include "map.h"

#define FIRST_LEVEL 1 // Index of the level loaded when the game starts (0 <= index < LEVEL_COUNT)
#define LEVEL_COUNT 2 // Total number of levels

/*
    Holds all the info of a level

    @param map_offset Location in the maps array
    @param map_size Size of the map of the level, in the form of position_2D
    @param player_spawn Location of the player when the level is loaded, in the form of position_2D
*/
typedef struct level_s {
    int map_offset;
    position_2D map_size;
    position_2D player_spawn;
} level_t;

extern level_t curr_lev_info; // Info of the current level
extern int current_level;     // Index of the current level

/*
    Returns the level offset for the maps list, to get the map of that level
*/
int get_map_offset(int level_idx);


/*
    Update the global variable curr_lev_info, to the info of the given level_idx
*/
void set_level_info(int level_idx);

#endif