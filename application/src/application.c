#include "Tom_Engine.h"
#include "app_test.h"

#include <math.h>

position_2D_t square_center = {200, 200};

float square_angle = 0;
position_2D_t square_pos = {200, 200};
float radious = 100;

void app_init(void)
{
    bar(2, 6);

    log_warning("This is the app!");
}

void app_update(float delta_time)
{
    if (is_key_being_pressed('p'))
    {
        log_warning("Delta time is currently: %f", delta_time);
    }

    if (is_key_just_pressed('o'))
    {
        log_warning("O just pressed!");
    }

    if (is_key_being_pressed('b'))
    {
        draw_point(square_pos, 100, COLOR_MAGENTA);
    }

    square_angle = adjust_angle(square_angle);

    square_pos.x = radious * cos(square_angle) + square_center.x;
    square_pos.y = radious * sin(square_angle) + square_center.y;

    square_angle += 0.1;
}

void app_close(void)
{
    log_warning("Good bye from app!");
}
