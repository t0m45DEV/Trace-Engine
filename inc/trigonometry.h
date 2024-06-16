#ifndef _H_TRIGONOMETRY
#define _H_TRIGONOMETRY

#include <math.h>

#define PI 3.1415926535
#define UP_DIR   (PI / 2)
#define DOWN_DIR (3 * (UP_DIR))


#define CALCULATE_X_DELTA(A) (cos(A))
#define CALCULATE_Y_DELTA(A) (sin(A))


float distance_between();

#endif