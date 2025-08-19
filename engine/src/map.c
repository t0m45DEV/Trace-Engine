#include "map.h"
#include "levels_info.h"

#include "graphics.h"
#include "game_state.h"

/**
 * Check if the given index is in range of the current level map
 *
 * @note curr_lev_info.mapp_offset <= idx < (curr_lev_info.mapp_offset + MAP_SIZE)
 */
static int is_valid_map_index(int idx)
{
    return ((idx > 0) && (idx < get_current_map_size()));
}

/**
 * Calculates the grid position for the given grid position
 */
int real_pos_to_map_pos(const trc_grid_position_t real_pos)
{
    return ((int) (real_pos.y)) * ((int) get_current_map_dimensions().x) + ((int) (real_pos.x));
}

trc_world_position_t to_world_pos(trc_grid_position_t grid_pos)
{
    trc_world_position_t world_pos;
    world_pos.x = grid_pos.x * (float) MAP_CELL_SIZE + ((float) MAP_CELL_SIZE / 2);
    world_pos.y = grid_pos.y * (float) MAP_CELL_SIZE + ((float) MAP_CELL_SIZE / 2);

    return world_pos;
}

trc_grid_position_t to_grid_pos(trc_world_position_t world_pos)
{
    trc_grid_position_t grid_pos;
    grid_pos.x = world_pos.x / (float) MAP_CELL_SIZE;
    grid_pos.y = world_pos.y / (float) MAP_CELL_SIZE;

    return grid_pos;
}

trc_world_position_t map_pos_to_real_pos(trc_world_position_t map_pos)
{
    float real_x = (map_pos.x * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2.0);
    float real_y = (map_pos.y * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2.0);

    return (trc_world_position_t) {real_x, real_y};
}

void change_to_map(int level_idx)
{
    int x_size = maps_sizes[level_idx].x;
    int y_size = maps_sizes[level_idx].y;

    for (int y = 0; y < y_size; y++)
    {
        int row = y * x_size;

        for (int x = 0; x < x_size; x++)
        {
            int actual_map_pos = get_current_map_offset() + row + x;
            
            current_w_map[x + row] = map_w[actual_map_pos];
            current_f_map[x + row] = map_f[actual_map_pos];
            current_c_map[x + row] = map_c[actual_map_pos];
        }
    }
}

void update_map_wall_at(const trc_grid_position_t position, const structures_t new_wall)
{
    current_w_map[real_pos_to_map_pos(position)] = new_wall;
}

structures_t get_map_wall_at(const trc_grid_position_t position)
{
    structures_t ret = UNDEFINED;
    int idx = real_pos_to_map_pos(position);

    if (is_valid_map_index(idx))
    {
        ret = current_w_map[idx];
    }
    return ret;
}

structures_t get_map_floor_at(const trc_grid_position_t position)
{
    structures_t ret = UNDEFINED;
    int idx = real_pos_to_map_pos(position);

    if (is_valid_map_index(idx))
    {
        ret = current_f_map[idx];
    }
    return ret;
}

structures_t get_map_ceiling_at(const trc_grid_position_t position)
{
    structures_t ret = UNDEFINED;
    int idx = real_pos_to_map_pos(position);

    if (is_valid_map_index(idx))
    {
        ret = current_c_map[idx];
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

trc_world_position_t get_map_size_from_id(const int level_idx)
{
    return maps_sizes[level_idx];
}

trc_world_position_t get_camera_spwan_from_id(const int level_idx)
{
    return camera_spawns[level_idx];
}

void draw_map_2D(void)
{
    trc_world_position_t grid_pos;

    for (int y = 0; y < get_current_map_dimensions().y; y++)
    {
        for (int x = 0; x < get_current_map_dimensions().x; x++)
        {
            rgb_t cell_color = COLOR_WHITE;

            if (get_map_wall_at((trc_grid_position_t) {x, y}) == AIR)
            {
                cell_color = COLOR_BLACK;
            }

            grid_pos.x = x * MAP_CELL_SIZE;
            grid_pos.y = y * MAP_CELL_SIZE;
            trc_world_position_t cell_size = (trc_world_position_t) {MAP_CELL_SIZE, MAP_CELL_SIZE};
            
            draw_square(grid_pos, cell_size, 1, cell_color);
        }
    }
}
