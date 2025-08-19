#ifndef _H_GAME_STATE
#define _H_GAME_STATE

#include <stdbool.h>
#include "trc_world_position.h"

/**
 * A scene represents a state for the game (like the main
 * menu, options menu, specific level, boos fight, etc)
 */
typedef enum {
    MAIN_MENU_SCENE, /** The main menu, the first scene */
    GAME_SCENE       /** Gameplay scene */
} scenes_t;

/**
 * Holds all the info of a level
 */
typedef struct {
    int map_offset;             /** Location in the maps array */
    trc_world_position_t map_size;     /** Size of the map of the level, in the form of position_2D */
    trc_world_position_t camera_spawn; /** Location of the camera when the level is loaded, in the form of position_2D */
} level_t;

/**
 * It holds the current info of the program and the game
 * itself, like the current level, scene, or if the game
 * is even running
 */
typedef struct {
    bool is_game_running;       /** Self explanatory */
    int fps;                    /** FPS of the current run */
    int current_scene;          /** The current scene to be showed */
    int current_level_idx;      /** The index of the current level */
    level_t current_level_info; /** The info of the current level */
    int is_on_debug_view_mode;  /** A debug top-down view of the current */
    bool shows_debug_pop_up;    /** Shows the debug pop-up windows */
} game_state_t;

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
 * Returns the map dimensions of the current level in a trc_world_position_t
 */
 trc_world_position_t get_current_map_dimensions(void);

/**
 * Returns the map size of the current level
 */
float get_current_map_size(void);

/**
 * Returns the current map offset for the levels map array
 */
int get_current_map_offset(void);

/**
 * Returns the camera spawn of the current level
 */
trc_world_position_t get_current_camera_spawn(void);

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
 * Update the current map and camera info to be the level_idx level 
 * 
 * @param level_idx The index of the level to get the info from (from 0 to LEVEL_COUNT)
 * 
 * @note Calling this function will RESET the level (every door will be to the original
 * state, the camera will be at the spawn of that level, etc)
 */
void load_level(const int level_idx);

/**
 * Resets the current level
 */
void reload_level(void);

#endif
