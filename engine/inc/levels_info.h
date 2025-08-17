#ifndef _H_LEVELS_INFO
#define _H_LEVELS_INFO

#include "map.h"

/** Maximum dimensions for a level */
#define MAX_MAP_SIZE 50 * 50

extern structures_t current_w_map[MAX_MAP_SIZE];
extern structures_t current_f_map[MAX_MAP_SIZE];
extern structures_t current_c_map[MAX_MAP_SIZE];

extern structures_t map_w[];
extern structures_t map_f[];
extern structures_t map_c[];

extern trc_world_position_t maps_sizes[LEVEL_COUNT];

extern trc_world_position_t camera_spawns[LEVEL_COUNT];


#endif