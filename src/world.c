#include "world.h"

int get_map_offset(const int level_idx)
{
    int ret = 0;

    for (int i = 0; i < level_idx; i++)
    {
        ret += (maps_sizes[i].x * maps_sizes[i].y);
    }
    return ret;
}


void set_level_info(const int level_idx)
{
    game_state.current_level_info.map_offset = get_map_offset(level_idx);
    game_state.current_level_info.map_size = maps_sizes[level_idx];
    game_state.current_level_info.player_spawn = player_spawns[level_idx];
}


void load_level(const int level_idx)
{
    game_state.current_level_idx = level_idx;
    set_level_info(level_idx);
    reset_player_info();
}
