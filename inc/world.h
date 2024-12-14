#ifndef _H_WORLD
#define _H_WORLD

#include "map.h"
#include "player.h"

/**
 * Returns the level offset for the maps list, to get the map of that level
 * 
 * @param level_idx The index of the level to get (from 0 to LEVEL_COUNT)
 */
int get_map_offset(int level_idx);


/**
 * Update the global variable curr_lev_info, to the info of the given level_idx
 * 
 * @param level_idx The index of the level to get the info from (from 0 to LEVEL_COUNT)
 */
void set_level_info(int level_idx);


/**
 * Loads the idx-th level, seting the player stats and the map
 * 
 * @param level_idx The index of the level to load
 */
void load_level(int level_idx);

#endif