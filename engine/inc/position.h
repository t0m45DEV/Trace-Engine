#ifndef _H_POS
#define _H_POS

/**
 * A vector of 2 dimensions, the values x and y are floats
 */
typedef struct {
    float x;  /** X component of the (x, y) vector */
    float y;  /** Y component of the (x, y) vector */
} position_2D_t;

#define TRC_POS_ORIGIN ((position_2D_t) {0, 0})

#endif
