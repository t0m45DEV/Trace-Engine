#include "input.h"

keys_state_t action_keys_state = {0};

void buttons_down(unsigned char key, int, int)
{
    if (key == CHANGE_DEBUG_MODE)
    {
        //debug_2D_view = !debug_2D_view;

        if (resolution == HIGH_RESOLUTION) resolution = LOW_RESOLUTION;
        else
        resolution = HIGH_RESOLUTION;

        //if (current_level == 0) change_to_level(1);
        //else change_to_level(0);
    }
    else if (key == MOVE_FORWARD)
    {
        action_keys_state.move_forward = 1;
    }
    else if (key == MOVE_BACKWARD)
    {
        action_keys_state.move_backward = 1;
    }
    else if (key == ROTATE_ANTI_CLOCKWISE)
    {
        action_keys_state.rotate_anti_clockwise = 1;
    }
    else if (key == ROTATE_CLOCKWISE)
    {
        action_keys_state.rotate_clockwise = 1;
    }
}

void buttons_up(unsigned char key, int, int)
{
    if (key == MOVE_FORWARD)
    {
        action_keys_state.move_forward = 0;
    }
    else if (key == MOVE_BACKWARD)
    {
        action_keys_state.move_backward = 0;
    }
    else if (key == ROTATE_ANTI_CLOCKWISE)
    {
        action_keys_state.rotate_anti_clockwise = 0;
    }
    else if (key == ROTATE_CLOCKWISE)
    {
        action_keys_state.rotate_clockwise = 0;
    }
}


void move_player(void)
{
    if (action_keys_state.rotate_anti_clockwise)
    {
        player.angle -= ROTATE_VELOCITY * FPS_CORRECTION;
        player.angle = adjust_angle(player.angle);
        
        player.delta.x = CALCULATE_X_DELTA(player.angle) * player.velocity;
        player.delta.y = CALCULATE_Y_DELTA(player.angle) * player.velocity;
    }
    if (action_keys_state.rotate_clockwise)
    {
        player.angle += ROTATE_VELOCITY * FPS_CORRECTION;
        player.angle = adjust_angle(player.angle);

        player.delta.x = CALCULATE_X_DELTA(player.angle) * player.velocity;
        player.delta.y = CALCULATE_Y_DELTA(player.angle) * player.velocity;
    }
    if (action_keys_state.move_forward)
    {
        if (!is_colliding_in_axis(player, FRONT_X_AXIS_COLLISION)) player.pos.x += player.delta.x * FPS_CORRECTION;
        if (!is_colliding_in_axis(player, FRONT_Y_AXIS_COLLISION)) player.pos.y += player.delta.y * FPS_CORRECTION;
    }
    if (action_keys_state.move_backward)
    {
        if (!is_colliding_in_axis(player, BACK_X_AXIS_COLLISION)) player.pos.x -= player.delta.x * FPS_CORRECTION;
        if (!is_colliding_in_axis(player, BACK_Y_AXIS_COLLISION)) player.pos.y -= player.delta.y * FPS_CORRECTION;
    }

    glutPostRedisplay();
}
