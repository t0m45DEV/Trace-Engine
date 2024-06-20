#ifndef _H_ENTITY
#define _H_ENTITY

#include <stdbool.h>
#include "map.h"
#include "trigonometry.h"

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
    position_2D pos;
    position_2D delta;
    float angle;
    float velocity;
    int collision_size;
    position_2D offset;
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