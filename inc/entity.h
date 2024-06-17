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
    @param collision_size Int
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

#endif