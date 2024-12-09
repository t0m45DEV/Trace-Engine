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


/*
    An entity is every interactive and moving thing in the game, including the player

    @param pos position_2D, where the entity is in the top view map
    @param delta position_2D, where the entity is looking at
    @param angle Float, the angle between pos and delta, in radians
    @param velocity Float, how fast the entity moves
    @param collision_size Int, radious of the collision shape (it's always a circle)
    @param offset position_2D, the offset is a point at distance collision_size from pos, we use this point to detect collisions
*/
typedef struct entity_s {
    position_2D pos;
    position_2D delta;
    float angle;
    float velocity;
    int collision_size;
    position_2D offset;
} entity_t;


/*
    Only for debug, it shows the entity info
*/
void print_entity(entity_t entity);

/*
    Returns the same entity with the x_offset and y_offset calculated using the entity angle

    @param entity An entity type, the engine asumes that delta have correct values
*/
entity_t calculate_offset(entity_t entity);


/*
    Returns true (not zero) if the thing at the position idx can move towards the offset position
*/
int can_move(position_2D idx, position_2D offset);


/*
    Given an entity and a collision position indicator, returns 0 if there is no collision in that direction, or another number of there is a collision
*/
int is_colliding_in_axis(entity_t entity, int axis);

#endif