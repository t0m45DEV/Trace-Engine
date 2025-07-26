#ifndef _H_TRIGONOMETRY
#define _H_TRIGONOMETRY

#include "position.h"
#include <stdbool.h>

#define PRECISION 0.0001   /** To compare doubles and floats */

#define DEGREE 0.0174533 /** One degree in radians */

#define PI 3.1415926535           /** An aproximation to pi */
#define UP_DIR    (PI / 2)        /** 90 degrees, or the angle in radians for ↑  */
#define DOWN_DIR  (3 * (UP_DIR))  /** 270 degrees, or the angle in radians for ↓ */
#define LEFT_DIR  (PI)            /** 180 degrees, or the angle in radians for ← */
#define RIGHT_DIR (PI * 0)        /** 0 degrees, or the angle in radians for → */

#define DEG_TO_RAD(angleInDegrees) (adjust_angle((angleInDegrees) * PI / 180.0)) /** Angle in degrees to angle in radians */
#define RAD_TO_DEG(angleInRadians) (adjust_angle(angleInRadians) * 180.0 / PI)   /** Angle in radians to angle in degrees */

// A float rename, for better reading
//typedef float angle_t;

#ifndef GAME_EXPORT
    /**
     * @note Remember to free the memory allocated for the string!
     */
    #define position_2D_to_string(X) position_2D_to_string_with_name(X, #X)

    /**
     * Only for debug, it returns the position in the form of a string with the format:
     * 
     * "pos_name = (pos.x, pos.y)"
     * 
     * @param pos position_2D_t, the position to print
     * 
     * @note Caller MUST free the memory allocated for the string
     */
    char* position_2D_to_string_with_name(const position_2D_t pos, const char* pos_name);
#else
    #define debug_position(X) // Does nothing
#endif

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