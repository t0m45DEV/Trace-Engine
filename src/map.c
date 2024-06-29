#include "map.h"

rgb_t structures_colors[] =
{
    (rgb_t) {0},
    (rgb_t) {1, 0, 0},
    (rgb_t) {0, 0, 1}
};

structures_t map[] =
{
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 1,
    1, 0, 1, 0, 1, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1,

    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1,
    1, 0, 2, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1,
    1, 0, 2, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1,
    1, 0, 2, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

position_2D maps_sizes[LEVEL_COUNT] =
{
    (position_2D) {8, 8},
    (position_2D) {16, 8}
};

position_2D player_spawns[LEVEL_COUNT] =
{
    (position_2D) {1, 6},
    (position_2D) {1, 1}
};


int is_valid_map_index(int idx)
{
    return ((idx > curr_lev_info.map_offset) && (idx < (curr_lev_info.map_offset + MAP_SIZE)));
}

void draw_map_2D(void)
{
    position_2D grid_pos;

    for (int y = 0; y < curr_lev_info.map_size.y; y++)
    {
        for (int x = 0; x < curr_lev_info.map_size.x; x++)
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
