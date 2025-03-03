#include "game_state.h"

game_state_t game_state = {0}; /** The current state of ALL the program */

void init_game_state(void)
{
    game_state.is_game_running = true;
    game_state.current_scene = GAME_SCENE;
    game_state.is_on_debug_view_mode = false;
    game_state.shows_debug_pop_up = false;
}

bool is_game_running(void)
{
    return game_state.is_game_running;
}

bool is_debug_console_on(void)
{
    return game_state.shows_debug_pop_up;
}

bool is_top_down_view_on(void)
{
    return game_state.is_on_debug_view_mode;
}

game_state_t get_game_state(void)
{
    return game_state;
}

scenes_t get_current_scene(void)
{
    return game_state.current_scene;
}

level_t get_current_level_info(void)
{
    return game_state.current_level_info;
}

position_2D_t get_current_map_size(void)
{
    return game_state.current_level_info.map_size;
}

position_2D_t get_current_player_spawn(void)
{
    return game_state.current_level_info.player_spawn;
}

int get_fps(void)
{
    return game_state.fps;
}

void update_game_state_fps(int fps)
{
    game_state.fps = fps;
}

void stop_game(void)
{
    game_state.is_game_running = false;
}

void update_debug_console_state(void)
{
    game_state.shows_debug_pop_up = !game_state.shows_debug_pop_up;
}

void set_level_info(const int level_idx)
{
    game_state.current_level_idx = level_idx;
    game_state.current_level_info.map_offset = get_map_offset(level_idx);
    game_state.current_level_info.map_size = maps_sizes[level_idx];
    game_state.current_level_info.player_spawn = player_spawns[level_idx];
}
