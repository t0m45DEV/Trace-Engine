#include "3D_render.h"

void render_line(float distance_from_player, int ray)
{
    float line_h = (MAP_CELL_SIZE * 320) / distance_from_player;
    float offset = 300 - line_h / 2;

    if (line_h > 320) line_h = 320;

    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2i(ray * 8 + 530, offset);
    glVertex2i(ray * 8 + 530, line_h + offset);
    glEnd();
}
