#include "Tom_Engine.h"
#include "app_test.h"


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
        draw_point((position_2D_t) {200, 200}, 100, COLOR_MAGENTA);
    }
}

void app_close(void)
{
    log_warning("Good bye from app!");
}
