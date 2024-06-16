#include "input.h"

void buttons(unsigned char key, int x, int y)
{
    if (key == CHANGE_DEBUG_MODE)
    {
        debug_2D_view = !debug_2D_view;
        show_3D_view = !show_3D_view;
    }
    else if (key == ROTATE_LEFT)
    {
        player.angle -= ROTATE_VELOCITY;
        player.angle = adjust_angle(player.angle);
        
        player.x_delta = CALCULATE_X_DELTA(player.angle) * player.velocity;
        player.y_delta = CALCULATE_Y_DELTA(player.angle) * player.velocity;
    }
    else if (key == ROTATE_RIGHT)
    {
        player.angle += ROTATE_VELOCITY;
        player.angle = adjust_angle(player.angle);

        player.x_delta = CALCULATE_X_DELTA(player.angle) * player.velocity;
        player.y_delta = CALCULATE_Y_DELTA(player.angle) * player.velocity;
    }
    else if (key == MOVE_FORWARD)
    {
        player.x_pos += player.x_delta;
        player.y_pos += player.y_delta;
    }
    else if (key == MOVE_BACKWARD)
    {
        player.x_pos -= player.x_delta;
        player.y_pos -= player.y_delta;
    }

    glutPostRedisplay();
}
