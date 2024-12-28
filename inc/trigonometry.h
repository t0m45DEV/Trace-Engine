#ifndef _H_TRIGONOMETRY
#define _H_TRIGONOMETRY

#include <math.h>

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
float adjust_angle(float angle);

#endif