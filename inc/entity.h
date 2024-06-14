#ifndef _H_ENTITY
#define _H_ENTITY

#include <math.h>

/*
    An entity is every interactive and moving thing in the game, including the player

    @param x_pos Float
    @param y_pos Float
    @param x_delta Float
    @param y_delta Float
    @param angle Float
    @param velocity Float
*/
typedef struct entity_s {
    float x_pos;
    float y_pos;
    float x_delta;
    float y_delta;
    float angle;
    float velocity;
} entity_t;


#define CALCULATE_X_DELTA(A) (cos(A))
#define CALCULATE_Y_DELTA(A) (sin(A))


#endif