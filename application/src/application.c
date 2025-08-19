#include "Tom_Engine.h"
#include "demo_player.h"

#include <math.h>

trc_world_position_t square_center = {200, 200};

angle_t square_angle = 0;
trc_world_position_t square_pos = {200, 200};
float radious = 100;

void app_init(void)
{
    log_warning("This is the app!");
}

void app_update(float delta_time)
{
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

    move_demo_player(delta_time);
}

void app_close(void)
{
    log_warning("Good bye from app!");
}
