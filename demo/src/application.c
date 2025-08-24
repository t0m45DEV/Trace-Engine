#include "Tom_Engine.h"
#include "demo_player.h"
#include "demo_square.h"

void app_init(void)
{
    log_warning("This is the app!");
}

void app_update(float delta_time)
{
    move_demo_square(delta_time);
    move_demo_player(delta_time);
}

void app_close(void)
{
    log_warning("Good bye from app!");
}
