#ifndef _H_DEFINES
#define _H_DEFINES

#include <stdbool.h>
#include "trigonometry.h"

/**
 * A scene represents a state for the game (like the main
 * menu, options menu, specific level, boos fight, etc)
 */
typedef enum {
    MAIN_MENU_SCENE, /**< The main menu, the first scene */
    GAME_SCENE       /**< Gameplay scene */
} scenes_t;

/**
 * Holds all the info of a level
 */
typedef struct {
    int map_offset;             /**< Location in the maps array */
    position_2D_t map_size;     /**< Size of the map of the level, in the form of position_2D */
    position_2D_t player_spawn; /**< Location of the player when the level is loaded, in the form of position_2D */
} level_t;

/**
 * It holds the current info of the program and the game
 * itself, like the current level, scene, or if the game
 * is even running
 */
typedef struct {
    bool is_game_running;       /**< Self explanatory */
    int current_scene;          /**< The current scene to be showed */
    int current_level_idx;      /**< The index of the current level */
    level_t current_level_info; /**< The info of the current level */
    bool is_on_debug_view_mode; /**< A debug top-down view of the current */
} game_state_t;

extern game_state_t game_state; /**< The current state of ALL the program */

#endif