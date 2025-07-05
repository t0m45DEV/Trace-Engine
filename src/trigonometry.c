#include "trigonometry.h"

#include "log.h"
#include <math.h>

#ifndef GAME_EXPORT
    #include <stdio.h>
    #include <stdlib.h>

    char* position_2D_to_string_with_name(const position_2D_t pos, const char* pos_name)
    {
        const int MAX_LEN = 50;
        char* string = malloc(sizeof(char) * MAX_LEN);

        int printf_out = snprintf(string, MAX_LEN, "%s = (%f, %f)", pos_name, pos.x, pos.y);

        if (printf_out <= 0)
        {
            log_error("There was an error parsing to string for %s", pos_name);
        }
        return string;
    }
#endif

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
