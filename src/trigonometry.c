#include "trigonometry.h"

float distance_between(float p1_x, float p1_y, float p2_x, float p2_y)
{
    return sqrt(((p1_x - p2_x) * (p1_x - p2_x)) + ((p1_y - p2_y) * (p1_y - p2_y)));
}

float adjust_angle(float angle)
{
    if (angle < 0)
    {
        angle += 2 * PI;
    }
    else if (angle > (2 * PI))
    {
        angle -= 2 * PI;
    }

    return angle;
}
