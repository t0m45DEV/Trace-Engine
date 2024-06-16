#include <GL/glut.h>

#include "input.h"
#include "player.h"
#include "trigonometry.h"


void buttons(unsigned char key, int x, int y)
{
    if (key == ROTATE_LEFT) {
        player.angle -= ROTATE_VELOCITY;

        if (player.angle < 0) {
            player.angle += 2 * PI;
        }
        player.x_delta = CALCULATE_X_DELTA(player.angle) * player.velocity;
        player.y_delta = CALCULATE_Y_DELTA(player.angle) * player.velocity;
    }
    else if (key == ROTATE_RIGHT) {
        player.angle += ROTATE_VELOCITY;

        if (player.angle > 2 * PI) {
            player.angle -= 2 * PI;
        }
        player.x_delta = CALCULATE_X_DELTA(player.angle) * player.velocity;
        player.y_delta = CALCULATE_Y_DELTA(player.angle) * player.velocity;
    }
    else if (key == MOVE_FORWARD) {
        player.x_pos += player.x_delta;
        player.y_pos += player.y_delta;
    }
    else if (key == MOVE_BACKWARD) {
        player.x_pos -= player.x_delta;
        player.y_pos -= player.y_delta;
    }

    glutPostRedisplay();
}
