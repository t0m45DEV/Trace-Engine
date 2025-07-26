#ifndef _H_STRUCTURE
#define _H_STRUCTURE

/**
 * Structures that can form the map
 */
typedef enum {
    UNDEFINED = -1, /** This structure is for error managing */
    AIR,            /** Nothing, the squares where the entities can move */
    STONE,
    WOOD,
    DOOR
} structures_t;

#endif