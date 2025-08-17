#include "game_state.h"

#include "log.h"
#include "trc_camera.h"
#include "map.h"

game_state_t game_state = {0}; /** The current state of ALL the program */

void init_game_state(void)
{
    game_state.is_game_running = true;
    game_state.current_scene = GAME_SCENE;
    game_state.is_on_debug_view_mode = false;
    game_state.shows_debug_pop_up = false;

    log_info("Game state initiliazed!");
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

game_state_t* get_game_state(void)
{
    return &game_state;
}

scenes_t get_current_scene(void)
{
    return game_state.current_scene;
}

int get_current_level_index(void)
{
    return game_state.current_level_idx;
}

level_t get_current_level_info(void)
{
    return game_state.current_level_info;
}

trc_world_position_t get_current_map_dimensions(void)
{
    return game_state.current_level_info.map_size;
}

float get_current_map_size(void)
{
    return game_state.current_level_info.map_size.x * game_state.current_level_info.map_size.y;
}

int get_current_map_offset(void)
{
    return game_state.current_level_info.map_offset;
}

trc_world_position_t get_current_camera_spawn(void)
{
    return game_state.current_level_info.camera_spawn;
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

void load_level(const int level_idx)
{
    game_state.current_level_idx = level_idx;
    game_state.current_level_info.map_offset = get_map_offset_from_id(level_idx);
    game_state.current_level_info.map_size = get_map_size_from_id(level_idx);
    game_state.current_level_info.camera_spawn = get_camera_spwan_from_id(level_idx);
    change_to_map(level_idx);
    reset_camera_info();

    log_info("Succesfully loaded the %i-th level!", level_idx);
}

void reload_level(void)
{
    load_level(get_current_level_index());
}
