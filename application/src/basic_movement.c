#include "basic_movement.h"

#include "Tom_Engine.h"
#include "trc_camera.h"
#include "trigonometry.h"

#define MOVE_FORWARD          'w'
#define MOVE_BACKWARD         's'
#define ROTATE_CLOCKWISE      'd'
#define ROTATE_ANTI_CLOCKWISE 'a'

const int movement_velocity = 100;
const int rotation_velocity = 2;

void move_player(const float delta_time)
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
        move_camera_sliding(scalar_multiplication(get_camera_direction(), movement_velocity * delta_time));
    }
    if (is_key_being_pressed(MOVE_BACKWARD))
    {
        move_camera_sliding(scalar_multiplication(get_camera_direction(), movement_velocity * delta_time * (-1)));
    }
}
