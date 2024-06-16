#ifndef _H_TRIGONOMETRY
#define _H_TRIGONOMETRY

#include <math.h>

#define DEGREE 0.0174533 // One degree in radians

#define PI 3.1415926535
#define UP_DIR   (PI / 2)
#define DOWN_DIR (3 * (UP_DIR))


#define CALCULATE_X_DELTA(A) (cos(A))
#define CALCULATE_Y_DELTA(A) (sin(A))


float distance_between(float p1_x, float p1_y, float p2_x, float p2_y);

#endif