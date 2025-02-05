#ifndef _H_TRIGONOMETRY
#define _H_TRIGONOMETRY

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define PRECISION 0.0001   /**< To compare doubles and floats */

#define DEGREE 0.0174533 /**< One degree in radians */

#define PI 3.1415926535           /**< An aproximation to pi */
#define UP_DIR    (PI / 2)        /**< 90 degrees, or the angle in radians for ↑  */
#define DOWN_DIR  (3 * (UP_DIR))  /**< 270 degrees, or the angle in radians for ↓ */
#define LEFT_DIR  (PI)            /**< 180 degrees, or the angle in radians for ← */
#define RIGHT_DIR (PI * 0)        /**< 0 degrees, or the angle in radians for → */

#define CALCULATE_X_DELTA(A) (cos(A))
#define CALCULATE_Y_DELTA(A) (sin(A))

#define DEG_TO_RAD(angleInDegrees) ((angleInDegrees) * PI / 180.0) /**< Angle in degrees to angle in radians */
#define RAD_TO_DEG(angleInRadians) ((angleInRadians) * 180.0 / PI) /**< Angle in radians to angle in degrees */

/**
 * A vector of 2 dimensions, the values x and y are floats
 */
typedef struct {
    float x;  /**< X component of the (x, y) vector */
    float y;  /**< Y component of the (x, y) vector */
} position_2D_t;

/**
 * Only for debug, it prints the position in a readable way
 * 
 * @param pos position_2D_t, the position to print
 */
void print_position(const position_2D_t pos);

/**
 * Returns the distance between p1 and p2
 * 
 * @param p1 First point
 * @param p2 Second point
 */
float distance_between(const position_2D_t p1, const position_2D_t p2);

/**
 * Returns the angle so it's in the range of 0 to 2*PI
 * 
 * @param angle The angle to adjust, in radians
 */
float adjust_angle(const float angle);

/**
 * Returns if the first float is equal to the second
 * 
 * @param f1 First float
 * @param f2 Second float
 */
bool are_equals(const float f1, const float f2);

#endif