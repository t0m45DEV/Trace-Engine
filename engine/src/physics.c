#include "physics.h"

#include "input.h"
#include "player.h"

void handle_physics(float delta_time)
{
    move_player(get_keys_state(), delta_time);
}
