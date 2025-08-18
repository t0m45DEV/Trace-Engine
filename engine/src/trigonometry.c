#include "trigonometry.h"

#include "log.h"
#include <math.h>

#ifndef GAME_EXPORT
    #include <stdio.h>
    #include <stdlib.h>

    char* trc_world_position_to_string_with_name(const trc_world_position_t pos, const char* pos_name)
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

float distance_between(const trc_world_position_t p1, const trc_world_position_t p2)
{
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

float vector_length(const trc_world_position_t vector)
{
    return distance_between(TRC_POS_ORIGIN, vector);
}

trc_world_position_t normalize_vector(const trc_world_position_t vector)
{
    float length = vector_length(vector);

    if (length == 0)
    {
        return TRC_POS_ORIGIN;
    }
    return scalar_multiplication(vector, 1 / length);
}

trc_world_position_t scalar_multiplication(const trc_world_position_t vector, const float scalar)
{
    trc_world_position_t new_pos;

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
