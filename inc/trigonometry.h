#ifndef _H_TRIGONOMETRY
#define _H_TRIGONOMETRY

#include <math.h>

#define DEGREE 0.0174533 // One degree in radians

#define PI 3.1415926535
#define UP_DIR   (PI / 2)
#define DOWN_DIR (3 * (UP_DIR))


#define CALCULATE_X_DELTA(A) (cos(A))
#define CALCULATE_Y_DELTA(A) (sin(A))


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