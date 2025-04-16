#include "trigonometry.h"

#include <stdio.h>
#include <math.h>

void print_position(const position_2D_t pos)
{
    printf("(%f, %f)\n", pos.x, pos.y);
}

float distance_between(const position_2D_t p1, const position_2D_t p2)
{
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

angle_t adjust_angle(const angle_t angle)
{
    angle_t new_angle = angle;

    if (angle < 0)
    {
        new_angle += 2 * PI;
    }
    else if (angle > (2 * PI))
    {
        new_angle -= 2 * PI;
    }
    return new_angle;
}

bool are_equals(const float f1, const float f2)
{
    return ((bool) (fabs(f1 - f2) < PRECISION));
}
