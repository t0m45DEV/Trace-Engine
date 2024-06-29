#include "map.h"

int current_level = 0;
level_t curr_lev_info = {0};

int get_map_offset(int level_idx)
{
    int ret = 0;

    for (int i = 0; i < level_idx; i++)
    {
        ret += (maps_sizes[i].x * maps_sizes[i].y);
    }
    return ret;
}


void set_level_info(int level_idx)
{
    curr_lev_info.map_offset = get_map_offset(level_idx);
    curr_lev_info.map_size = maps_sizes[level_idx];
    curr_lev_info.player_spawn = player_spawns[level_idx];
}
