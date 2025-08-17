#include "demo_player.h"

#include "Tom_Engine.h"
#include <math.h>

#define MOVE_FORWARD  'w'
#define MOVE_BACKWARD 's'

const int velocity = 100;

void move_demo_player(float delta_time)
{
    trc_world_position_t modified_pos = get_camera_position();
    float current_angle = get_camera_angle();

    if (is_key_being_pressed(MOVE_FORWARD))
    {
        modified_pos.x += cos(current_angle) * velocity * delta_time;
        modified_pos.y += sin(current_angle) * velocity * delta_time;
    }
    else if (is_key_being_pressed(MOVE_BACKWARD))
    {
        modified_pos.x -= cos(current_angle) * velocity * delta_time;
        modified_pos.y -= sin(current_angle) * velocity * delta_time;
    }

    set_camera_position(modified_pos);
}
