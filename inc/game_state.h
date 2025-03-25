#ifndef _H_GAME_STATE
#define _H_GAME_STATE

#include "defines.h"

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
game_state_t* get_game_state(void);

/**
 * Returns the current scene being played
 */
scenes_t get_current_scene(void);

/**
 * Returns the current level id
 */
int get_current_level_index(void);

/**
 * Returns the info of the current level
 */
level_t get_current_level_info(void);

/**
 * Returns the map size of the current level
 */
position_2D_t get_current_map_size(void);

/**
 * Returns the current map offset for the levels map array
 */
int get_current_map_offset(void);

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
 * Update the current map and player info to be the level_idx level 
 * 
 * @param level_idx The index of the level to get the info from (from 0 to LEVEL_COUNT)
 * 
 * @note Calling this function will RESET the level (every door will be to the original
 * state, the player will be at the spawn of that level, etc)
 */
void load_level(const int level_idx);

/**
 * Resets the current level
 */
void reload_level(void);

#endif
