#ifndef _H_ENTITY
#define _H_ENTITY

#include "position.h"

typedef enum {
    BACK_Y_AXIS_COLLISION = -2,
    BACK_X_AXIS_COLLISION,
    NO_COLLISION,
    FRONT_X_AXIS_COLLISION,
    FRONT_Y_AXIS_COLLISION
} collision_directions_t;

/**
 * An entity is every interactive and moving thing in the game, including the player
 */
typedef struct {
    position_2D_t pos;       /** Where the entity is in the top view map */
    position_2D_t delta;     /** Where the entity is looking at */
    float angle;             /** The angle between pos and delta, in radians */
    float movement_velocity; /** How fast the entity moves */
    float rotation_velocity; /** How fast the entity rotates */
    int collision_size;      /** Radious of the collision shape (it's always a circle) */
    position_2D_t offset;    /** The offset is a point at distance collision_size from pos, we use this point to detect collisions */
} entity_t;

#ifndef GAME_EXPORT
    /**
     * @note Remember to free the memory allocated for the string!
     */
    #define entity_to_string(X) entity_to_string_with_name(X, #X)

    /**
     * Only for debug, it returns the entity info in the form of a string
     * 
     * @param entity entity_t, the entity to print
     * 
     * @note Caller MUST free the memory allocated for the string
     */
    char* entity_to_string_with_name(const entity_t entity, const char* entity_name);
#else
    #define debug_entity(X) // Does nothing
#endif

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
int can_move(const position_2D_t idx, const position_2D_t offset);


/**
 * Given an entity and a collision position indicator, returns 0 if there is no collision in that direction, or another number of there is a collision
 * 
 * @param entity The entity that the function will check
 * @param axis The axis of collision to check (X and Y axis, collision from front and the back)
 */
int is_colliding_in_axis(const entity_t entity, const collision_directions_t axis);

#endif