#include "trigonometry.h"

float distance_between(position_2D_t p1, position_2D_t p2)
{
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
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
