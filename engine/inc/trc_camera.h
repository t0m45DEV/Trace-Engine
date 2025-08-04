#ifndef TRC_CAMERA
#define TRC_CAMERA

#include "position.h"
#include "basic_input.h"

/**
 * Returns the current camera position
 */
position_2D_t get_camera_position(void);

/**
 * Moves the camera to new_pos
 */
void set_camera_position(position_2D_t new_pos);

/**
 * Returns the current camera angle of vision (in radians)
 */
float get_camera_angle(void);

/**
 * Sets the camera info to the current level 
 *
 * @note If you change or reset the level, call this function to update the camera position, velocity, etc
 */
void reset_camera_info(void);

/**
 * Move the camera using the info in the camera struct from camera.h and the action_key_state struct from input.h
 */
void move_camera(keys_state_t key_state, float delta_time);

/**
 * Draw the camera in the screen in the actual camera position.
 *
 * @note The camera is represented as a yellow dot with a line in front of him. This line represent the face of the camera.
 */
void draw_camera(void);

/**
 * Check if is a door infront of the camera. If that's true, opens the door
 */
void open_door(void);

#endif
