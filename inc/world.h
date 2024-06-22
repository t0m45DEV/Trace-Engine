#ifndef _H_WORLD
#define _H_WORLD

#include "map.h"

typedef struct level_s {
    position_2D player_spawn;
    position_2D map_size;
    enum structures* map;
} level;


extern const int LEVELS_COUNT;
extern level levels[];
extern int current_level;

#endif