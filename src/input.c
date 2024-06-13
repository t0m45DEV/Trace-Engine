#include <GL/glut.h>

#include "input.h"
#include "player.h"


void buttons(unsigned char key, int x, int y)
{
    if (key == ROTATE_RIGHT) {
        player_angle -= ROTATE_VELOCITY;

        if (player_angle < 0) {
            player_angle += 2 * PI;
        }
        player_x_delta = CALCULATE_X_DELTA(player_angle);
        player_y_delta = CALCULATE_Y_DELTA(player_angle);
    }
    else if (key == ROTATE_LEFT) {
        player_angle += ROTATE_VELOCITY;

        if (player_angle > 2 * PI) {
            player_angle -= 2 * PI;
        }
        player_x_delta = CALCULATE_X_DELTA(player_angle);
        player_y_delta = CALCULATE_Y_DELTA(player_angle);
    }
    else if (key == MOVE_FORWARD) {
        player_x_pos += player_x_delta;
        player_y_pos += player_y_delta;
    }
    else if (key == MOVE_BACKWARD) {
        player_x_pos -= player_x_delta;
        player_y_pos -= player_y_delta;
    }

    glutPostRedisplay();
}
