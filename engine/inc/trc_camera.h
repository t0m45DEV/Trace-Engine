#ifndef TRC_CAMERA
#define TRC_CAMERA

#include "trc_world_position.h"

/**
 * Returns the current camera position
 */
trc_world_position_t get_camera_position(void);

/**
 * Moves the camera with the given velocity, will slide along the walls if a collision is detected
 */
void move_camera_sliding(const trc_world_position_t velocity);

/**
 * Moves the camera with the given velocity, will stop fucking moving if a collision is detected
 */
void move_camera_colliding(const trc_world_position_t velocity);

/**
 * Rotates the camera adding the given delta to the current camera angle
 * 
 * @note The sign of rotation_delta determines the direction of the rotation
 */
void rotate_camera(const float rotation_delta);

/**
 * Returns the current camera direction, in the form of a normalized vector
 */
trc_world_position_t get_camera_direction(void);

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
