#include "Tom_Engine.h"
#include "app_test.h"


void init_game(void)
{
    bar(2, 6);

    log_warning("This is the app!");
}

void update_game(float delta_time)
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
        log_warning("B being pressed");
    }
}

void close_game(void)
{
    log_warning("Good bye from app!");
}
