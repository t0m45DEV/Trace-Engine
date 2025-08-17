#ifndef TRC_POS
#define TRC_POS

/**
 * A vector of 2 dimensions, the values x and y are floats
 */
typedef struct {
    float x;  /** X component of the (x, y) vector */
    float y;  /** Y component of the (x, y) vector */
} trc_world_position_t;

#define TRC_POS_ORIGIN ((trc_world_position_t) {0, 0})

#endif
