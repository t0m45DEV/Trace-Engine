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

float vector_length(const position_2D_t vector)
{
    return distance_between(TRC_POS_ORIGIN, vector);
}

position_2D_t normalize_vector(const position_2D_t vector)
{
    float length = vector_length(vector);

    position_2D_t new_vector;
    new_vector.x = vector.x / length;
    new_vector.y = vector.y / length;

    return new_vector;
}

position_2D_t scalar_multiplication(const position_2D_t vector, const float scalar)
{
    position_2D_t new_pos;

    new_pos.x = vector.x * scalar;
    new_pos.y = vector.y * scalar;

    return new_pos;
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
