#include "3D_render.h"

void render_line(float distance_from_player, int ray)
{
    float line_h = (MAP_CELL_SIZE * WINDOW_HEIGHT) / distance_from_player;
    float offset = (Y_CORRECTION) - line_h / 2;

    if (line_h > MAX_WALL_HEIGHT) line_h = MAX_WALL_HEIGHT;

    glLineWidth(LINES_WIDTH);
    glBegin(GL_LINES);
    glVertex2i(ray * LINES_WIDTH + X_CORRECTION, offset);
    glVertex2i(ray * LINES_WIDTH + X_CORRECTION, line_h + offset);
    glEnd();
}
