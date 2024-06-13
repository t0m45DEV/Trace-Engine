#include <GL/glut.h>

#include "map.h"


int map[] =
{
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1
};


void draw_map_2D(void)
{
    int x_square;
    int y_square;

    for (int y = 0; y < MAP_Y_SIZE; y++)
    {
        for (int x = 0; x < MAP_X_SIZE; x++)
        {
            if (map[(y * MAP_X_SIZE) + x] == 1)
            {
                glColor3f(1, 1, 1);
            }
            else
            {
                glColor3f(0, 0, 0);
            }

            x_square = x * MAP_CELL_SIZE;
            y_square = y * MAP_CELL_SIZE;
            glBegin(GL_QUADS);
            glVertex2i(x_square                 + 1, y_square                 + 1);
            glVertex2i(x_square                 + 1, y_square + MAP_CELL_SIZE - 1);
            glVertex2i(x_square + MAP_CELL_SIZE - 1, y_square + MAP_CELL_SIZE - 1);
            glVertex2i(x_square + MAP_CELL_SIZE - 1, y_square                 + 1);
            glEnd();
        }
    }
}
