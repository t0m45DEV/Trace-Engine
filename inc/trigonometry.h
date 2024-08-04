#ifndef _H_TRIGONOMETRY
#define _H_TRIGONOMETRY

#include <math.h>

#define DEGREE 0.0174533 /* One degree in radians */

#define PI 3.1415926535           /* An aproximation to pi */
#define UP_DIR    (PI / 2)        /* 90 degrees, or the angle in radians for ↑  */
#define DOWN_DIR  (3 * (UP_DIR))  /* 270 degrees, or the angle in radians for ↓ */
#define LEFT_DIR  (PI)            /*180 degrees, or the angle in radians for ← */
#define RIGHT_DIR (PI * 0)        /*0 degrees, or the angle in radians for → */

#define CALCULATE_X_DELTA(A) (cos(A))
#define CALCULATE_Y_DELTA(A) (sin(A))

/*
    A vector of 2 dimensions, the values x and y are floats
*/
typedef struct position_2D_s {
    float x;
    float y;
} position_2D;

/*
    Returns the distance between p1 and p2
*/
float distance_between(position_2D p1, position_2D p2);

/*
    Returns the angle so it's in the range of 0 to 2*PI
*/
float adjust_angle(float angle);

#endif