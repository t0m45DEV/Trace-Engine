#ifndef _H_ENTITY
#define _H_ENTITY

#include <stdbool.h>
#include "map.h"

/*
    An entity is every interactive and moving thing in the game, including the player

    @param x_pos Float
    @param y_pos Float
    @param x_delta Float
    @param y_delta Float
    @param angle Float
    @param velocity Float
    @param collision_size Int
    @param x_offset Float
    @param y_offset Float
*/
typedef struct entity_s {
    float x_pos;
    float y_pos;
    float x_delta;
    float y_delta;
    float angle;
    float velocity;
    int collision_size;
    float x_offset;
    float y_offset;
} entity_t;


/*
    Returns the same entity with the x_offset and y_offset calculated

    @param entity An entity type, the engine asumes that x_delta and y_delta have correct values
*/
entity_t calculate_offset(entity_t entity);


#define FRONT_X_AXIS_COLLISION 1
#define FRONT_Y_AXIS_COLLISION 2
#define BACK_X_AXIS_COLLISION -1
#define BACK_Y_AXIS_COLLISION -2
#define NO_COLLISION 0

/*
    Given an entity and a collision position indicator, returns 0 if there is no collision in that direction, or another number of there is a collision
*/
int is_colliding_in_axis(entity_t entity, int axis);

#endif