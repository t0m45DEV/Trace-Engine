#ifndef _H_PLAYER
#define _H_PLAYER

#include <math.h>


#define PI 3.1415926535

#define MOVE_VELOCITY    5
#define ROTATE_VELOCITY  0.1

#define P_INIT_X_POS  300.0
#define P_INIT_Y_POS  300.0

#define CALCULATE_X_DELTA(A) (cos(A) * MOVE_VELOCITY)
#define CALCULATE_Y_DELTA(A) (sin(A) * MOVE_VELOCITY)

extern float player_x_pos;
extern float player_y_pos;
extern float player_x_delta;
extern float player_y_delta;
extern float player_angle;


void draw_player(float x_pos, float y_pos);

#endif