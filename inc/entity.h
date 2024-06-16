#ifndef _H_ENTITY
#define _H_ENTITY

/*
    An entity is every interactive and moving thing in the game, including the player

    @param x_pos Float
    @param y_pos Float
    @param x_delta Float
    @param y_delta Float
    @param angle Float
    @param velocity Float
*/
typedef struct {
    float x_pos;
    float y_pos;
    float x_delta;
    float y_delta;
    float angle;
    float velocity;
} entity_t;


#endif