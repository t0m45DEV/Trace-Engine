#include <GL/glut.h>

#include <player.h>


float player_x_pos = P_INIT_X_POS;
float player_y_pos = P_INIT_Y_POS;
float player_angle = 0;
float player_x_delta = MOVE_VELOCITY; // CALCULATE_X_DELTA(player_angle)
float player_y_delta = 0;             // CALCULATE_Y_DELTA(player_angle)


/*
    Draw the player in the screen in the given position.

    The player is represented as a yellow dot with a line in front of him. This line represent the face of the player.
*/
void draw_player(float x_pos, float y_pos)
{
    player_x_pos = x_pos;
    player_y_pos = y_pos;

    glColor3f(1, 0, 0);
    glPointSize(12);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glVertex2i(player_x_pos, player_y_pos);
    glEnd();

    float look_x_dir = player_x_pos + player_x_delta * MOVE_VELOCITY;
    float look_y_dir = player_y_pos + player_y_delta * MOVE_VELOCITY;

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(player_x_pos, player_y_pos);
    glVertex2i(look_x_dir, look_y_dir);
    glEnd();
}
