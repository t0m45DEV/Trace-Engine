#include "demo_player.h"

#include "demo_controls.h"

#include "Tom_Engine.h"
#include "trc_camera.h"
#include "trigonometry.h"

const int movement_velocity = 100;
const int rotation_velocity = 2;

void move_demo_player(float delta_time)
{
    if (is_key_being_pressed(ROTATE_CLOCKWISE))
    {
        rotate_camera(rotation_velocity * delta_time);
    }
    if (is_key_being_pressed(ROTATE_ANTI_CLOCKWISE))
    {
        rotate_camera(rotation_velocity * delta_time * (-1));
    }

    if (is_key_being_pressed(MOVE_FORWARD))
    {
        move_camera(scalar_multiplication(get_camera_direction(), movement_velocity * delta_time));
    }
    if (is_key_being_pressed(MOVE_BACKWARD))
    {
        move_camera(scalar_multiplication(get_camera_direction(), movement_velocity * delta_time * (-1)));
    }
}
