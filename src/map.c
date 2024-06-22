#include "map.h"

structures map[] =
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1,
    1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};


void draw_map_2D(void)
{
    position_2D grid_pos;

    for (int y = 0; y < MAP_Y_SIZE; y++)
    {
        for (int x = 0; x < MAP_X_SIZE; x++)
        {
            if (map[REAL_POS_TO_GRID_POS(x, y)] == AIR)
            {
                glColor3f(0, 0, 0);
            }
            else
            {
                glColor3f(1, 1, 1);
            }

            grid_pos.x = x * MAP_CELL_SIZE;
            grid_pos.y = y * MAP_CELL_SIZE;
            glBegin(GL_QUADS);
            glVertex2i(grid_pos.x                 + 1, grid_pos.y                 + 1);
            glVertex2i(grid_pos.x                 + 1, grid_pos.y + MAP_CELL_SIZE - 1);
            glVertex2i(grid_pos.x + MAP_CELL_SIZE - 1, grid_pos.y + MAP_CELL_SIZE - 1);
            glVertex2i(grid_pos.x + MAP_CELL_SIZE - 1, grid_pos.y                 + 1);
            glEnd();
        }
    }
}
