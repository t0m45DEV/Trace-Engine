#ifndef _H_GAME_STATE
#define _H_GAME_STATE

#include "defines.h"
#include "map.h"

/**
 * Initialize the state of the game
 */
void init_game_state(void);

/**
 * Returns if the game is currently running
 */
bool is_game_running(void);

/**
 * Returns if the debug console is begin shown
 */
bool is_debug_console_on(void);

/**
 * Returns if the 2D top down view of the map is being shown
 */
bool is_top_down_view_on(void);

/**
 * Returns the current game state
 */
game_state_t get_game_state(void);

/**
 * Returns the current scene being played
 */
scenes_t get_current_scene(void);

/**
 * Returns the info of the current level
 */
level_t get_current_level_info(void);

/**
 * Returns the map size of the current level
 */
position_2D_t get_current_map_size(void);

/**
 * Returns the player spawn of the current level
 */
position_2D_t get_current_player_spawn(void);

/**
 * Returns the current FPS count
 */
int get_fps(void);

/**
 * Updates the count frame per second
 */
void update_game_state_fps(int fps);

/**
 * Sets the game_running variable to false
 */
void stop_game(void);

/**
 * If the debug console is being shown, this turns it off
 * 
 * If the debug console is hidden, this turns it on
 */
void update_debug_console_state(void);

/**
 * Returns the level offset for the maps list, to get the map of that level
 * 
 * @param level_idx The index of the level to get (from 0 to LEVEL_COUNT)
 */
int get_map_offset(const int level_idx);

/**
 * Update the global variable curr_lev_info, to the info of the given level_idx
 * 
 * @param level_idx The index of the level to get the info from (from 0 to LEVEL_COUNT)
 */
void set_level_info(const int level_idx);

#endif
