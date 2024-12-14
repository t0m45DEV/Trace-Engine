#ifndef _H_ENTITY
#define _H_ENTITY

#include <stdio.h>

#include "map.h"
#include "trigonometry.h"

#define FRONT_X_AXIS_COLLISION 1
#define FRONT_Y_AXIS_COLLISION 2
#define BACK_X_AXIS_COLLISION -1
#define BACK_Y_AXIS_COLLISION -2
#define NO_COLLISION 0


/**
 * An entity is every interactive and moving thing in the game, including the player
 */
typedef struct {
    position_2D_t pos;    /**< Where the entity is in the top view map */
    position_2D_t delta;  /**< Where the entity is looking at */
    float angle;        /**< The angle between pos and delta, in radians */
    float velocity;     /**< How fast the entity moves */
    int collision_size; /**< Radious of the collision shape (it's always a circle) */
    position_2D_t offset; /**< The offset is a point at distance collision_size from pos, we use this point to detect collisions */
} entity_t;


/**
 * Only for debug, it shows the entity info
 * 
 * @param entity entity_t, the entity to print
 */
void print_entity(entity_t entity);

/**
 * Returns the same entity with the x_offset and y_offset calculated using the entity angle
 *
 * @param entity An entity type, the engine asumes that delta have correct values
 */
void update_offset(entity_t* entity);


/**
 * Returns true (not zero) if the thing at the position idx can move towards the offset position
 * 
 * @param idx The actual position of the object
 * @param offset The direction in whichc the object wants to move
 */
int can_move(position_2D_t idx, position_2D_t offset);


/**
 * Given an entity and a collision position indicator, returns 0 if there is no collision in that direction, or another number of there is a collision
 * 
 * @param entity The entity that the function will check
 * @param axis The axis of collision to check (X and Y axis, collision from front and the back)
 */
int is_colliding_in_axis(entity_t entity, int axis);

#endif