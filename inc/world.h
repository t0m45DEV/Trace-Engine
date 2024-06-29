#ifndef _H_WORLD
#define _H_WORLD

#include "map.h"

#define FIRST_LEVEL 1

typedef struct level_s {
    int map_offset;
    position_2D map_size;
    position_2D player_spawn;
} level_t;

extern level_t curr_lev_info;
extern int current_level;

/*
    Returns the level offset for the maps list, to get the map of that level
*/
int get_map_offset(int level_idx);


/*
    Update the global variable curr_lev_info, to the info of the given level_idx
*/
void set_level_info(int level_idx);

#endif