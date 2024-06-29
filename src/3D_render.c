#include "3D_render.h"

void set_wall_color(structures_t surface, float shade)
{
    float red   = structures_colors[surface].r * shade;
    float green = structures_colors[surface].g * shade;
    float blue  = structures_colors[surface].b * shade;

    glColor3f(red, green, blue);
}


void render_line(float distance_from_player, int ray)
{
    float line_h = (MAP_CELL_SIZE * WINDOW_HEIGHT) / distance_from_player;
    if (line_h > MAX_WALL_HEIGHT) line_h = MAX_WALL_HEIGHT;
    float offset = (Y_CORRECTION) - line_h / 2;

    glLineWidth(LINES_WIDTH);
    glBegin(GL_LINES);
    glVertex2i(ray * LINES_WIDTH + X_CORRECTION, offset);
    glVertex2i(ray * LINES_WIDTH + X_CORRECTION, line_h + offset);
    glEnd();
}
