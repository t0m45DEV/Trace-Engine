#include "physics.h"

float delta_time = 0;

void handle_physics(void)
{
    move_player(delta_time);
}
