#ifndef _H_WORLD
#define _H_WORLD

#include "map.h"
#include "player.h"

/*
    Returns the level offset for the maps list, to get the map of that level
*/
int get_map_offset(int level_idx);


/*
    Update the global variable curr_lev_info, to the info of the given level_idx
*/
void set_level_info(int level_idx);


/*
    Loads the idx-th level, seting the player stats and the map
*/
void change_to_level(int level_idx);

#endif