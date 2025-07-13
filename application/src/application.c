#include "Tom_Engine.h"
#include "app_test.h"


void init_game(void)
{
    bar(2, 6);

    log_warning("This is the app!");
}

void update_game(float delta_time)
{
    log_warning("Delta time is currently: %f", delta_time);
}

void close_game(void)
{
    log_warning("Good bye from app!");
}
