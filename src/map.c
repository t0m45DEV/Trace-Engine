#include "map.h"

#include "levels/levels_info.c"

/**
 * Check if the given index is in range of the current level map
 *
 * @note curr_lev_info.mapp_offset <= idx < (curr_lev_info.mapp_offset + MAP_SIZE)
 */
static int is_valid_map_index(int idx)
{
    return ((idx > get_current_map_offset()) && (idx < (get_current_map_offset() + MAP_SIZE)));
}

void update_map_wall_at(const position_2D_t position, const structures_t new_wall)
{
    map_w[REAL_POS_TO_GRID_POS(position.x, position.y)] = new_wall;
}

structures_t get_map_wall_at(const position_2D_t position)
{
    structures_t ret = UNDEFINED;
    int idx = REAL_POS_TO_GRID_POS(position.x, position.y);

    if (is_valid_map_index(idx))
    {
        ret = map_w[idx];
    }
    return ret;
}

structures_t get_map_floor_at(const position_2D_t position)
{
    structures_t ret = UNDEFINED;
    int idx = REAL_POS_TO_GRID_POS(position.x, position.y);

    if (is_valid_map_index(idx))
    {
        ret = map_f[idx];
    }
    return ret;
}

structures_t get_map_ceiling_at(const position_2D_t position)
{
    structures_t ret = UNDEFINED;
    int idx = REAL_POS_TO_GRID_POS(position.x, position.y);

    if (is_valid_map_index(idx))
    {
        ret = map_c[idx];
    }
    return ret;
}

int get_map_offset_from_id(const int level_idx)
{
    int ret = 0;

    for (int i = 0; i < level_idx; i++)
    {
        ret += (maps_sizes[i].x * maps_sizes[i].y);
    }
    return ret;
}

position_2D_t get_map_size_from_id(const int level_idx)
{
    return maps_sizes[level_idx];
}

position_2D_t get_player_spwan_from_id(const int level_idx)
{
    return player_spawns[level_idx];
}

void draw_map_2D(void)
{
    position_2D_t grid_pos;

    for (int y = 0; y < get_current_map_size().y; y++)
    {
        for (int x = 0; x < get_current_map_size().x; x++)
        {
            if (map_w[REAL_POS_TO_GRID_POS(x, y)] == AIR)
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
