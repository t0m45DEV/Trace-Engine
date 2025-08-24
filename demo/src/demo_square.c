#include "Tom_Engine.h"

#include "demo_controls.h"

#include <math.h>

const trc_world_position_t orbit_center = {200, 200};
const float orbit_radious = 100;
const int orbit_velocity = 3;

float orbit_angle = 0;

trc_world_position_t square_pos = {200, 200};

void move_demo_square(float delta_time)
{
    if (is_key_being_pressed(SHOW_SQUARE_KEY))
    {
        draw_point(square_pos, 100, COLOR_MAGENTA);
    }

    orbit_angle = adjust_angle(orbit_angle);

    square_pos.x = orbit_radious * cos(orbit_angle) + orbit_center.x;
    square_pos.y = orbit_radious * sin(orbit_angle) + orbit_center.y;

    orbit_angle += orbit_velocity * delta_time;
}

