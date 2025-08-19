#ifndef TRC_TRANSFORM
#define TRC_TRANSFORM

#include "trc_world_position.h"
#include "trigonometry.h"

/**
 * A transform is like a point in 2D space, it has a position
 * in that space, a direction in which is looking, and a size
 * (for like areas or entities)
 */
typedef struct {
    trc_world_position_t pos;
    float angle;
    int size;
} trc_transform_t;

/**
 * Moves the given transform in the specified direction, unless
 * there is a wall within a distance equal to the transform's size
 * 
 * If that occurs, the transform will slide across the wall
 * (losing velocity according with the collision angle)
 * 
 * The velocity vector specifies both the direction and the speed of the transform
 */
void move_and_slide(trc_transform_t* transform, const trc_world_position_t velocity);

/**
 * Rotates the transform direction in the given signed angle
 * 
 * @note The direction is determined by the sign of rotation_velocity,
 * if it's positive then the rotation will be anti-clockwise, if it's
 * negative then it'll be clockwise
 */
void rotate_transform(trc_transform_t* transform, const angle_t rotation_delta);

#endif
