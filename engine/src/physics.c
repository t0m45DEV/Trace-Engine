#include "physics.h"

#include "basic_input.h"
#include "trc_camera.h"

void handle_physics(float delta_time)
{
    move_camera(get_keys_state(), delta_time);
}
