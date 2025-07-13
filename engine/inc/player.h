#ifndef _H_PLAYER
#define _H_PLAYER

#include "trigonometry.h"
#include "basic_input.h"

/**
 * Returns the current player position
 */
position_2D_t get_player_position(void);

/**
 * Returns the current player angle of vision (in radians)
 */
angle_t get_player_angle(void);

/**
 * Sets the player info to the current level 
 *
 * @note If you change or reset the level, call this function to update the player position, velocity, etc
 */
void reset_player_info(void);

/**
 * Move the player using the info in the player struct from player.h and the action_key_state struct from input.h
 */
void move_player(keys_state_t key_state, float delta_time);

/**
 * Draw the player in the screen in the actual player position.
 *
 * @note The player is represented as a yellow dot with a line in front of him. This line represent the face of the player.
 */
void draw_player(void);

/**
 * Check if is a door infront of the player. If that's true, opens the door
 */
void open_door(void);

#endif
