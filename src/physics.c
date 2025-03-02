#include "physics.h"

void handle_physics(float delta_time)
{
    move_player(get_key_state(), delta_time);
}
