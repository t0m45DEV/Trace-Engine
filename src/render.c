#include "render.h"

#include "defines.h"
#include "raycaster.h"
#include "trigonometry.h"
#include "window_display.h"
#include "player.h"
#include "all_textures.h"

#define RENDER_CHUNK_SIZE (4)                                 /** How many blocks away can the player see */
#define RENDER_DISTANCE (MAP_CELL_SIZE * RENDER_CHUNK_SIZE)   /** Distance between the player and the further object visible */

#define MAX_WALL_HEIGHT (VIEWPORT_HEIGHT)                             /** A rename for VIEWPORT_HEIGHT, for easier code reading */
#define LINES_WIDTH ((int) (VIEWPORT_WIDTH / get_ammount_of_rays()))  /** Ammount of pixels each ray will draw on screen      */
#define X_CORRECTION (LINES_WIDTH / 2.0)                              /** Correction for X axis to get the screen centered    */
#define Y_CORRECTION (VIEWPORT_HEIGHT / 2.0)                          /** Correction for Y axis to get the screen centered    */

#define DISTANCE_CORRECTION (((float) VIEWPORT_WIDTH) / ((float) VIEWPORT_HEIGHT)) /** To see the walls square */

#define FLOOR_CORRECTION ((VIEWPORT_WIDTH / 2.0) - 4)     /** The floor (and also the ceiling) stops sliding with this one */
#define CEILEING_CORRECTION (8.0 / get_actual_resolution()) /** The ceiling stops covering the walls */

void render_line(const ray_t ray)
{
    position_2D_t player_pos = get_player_position();
    angle_t player_angle = get_player_angle();

    float line_h = ((MAP_CELL_SIZE * VIEWPORT_HEIGHT) / ray.distance) * DISTANCE_CORRECTION;
    
    float texture_y_step = TEXTURE_SIZE / (float) line_h;
    float texture_y_offset = 0;
    
    if (line_h > MAX_WALL_HEIGHT)
    {
        texture_y_offset = (line_h - VIEWPORT_HEIGHT) / 2;
        line_h = MAX_WALL_HEIGHT;
    }

    float line_offset = (Y_CORRECTION) - line_h / 2;
    float texture_y = (texture_y_offset * texture_y_step) - 1;
    float texture_x;

    if (are_equals(ray.wall_orientation, NORTH_SOUTH_WALL))
    {
        texture_x = (int) (ray.pos.x / 2.0) % TEXTURE_SIZE;
        if (ray.angle < LEFT_DIR) texture_x = (TEXTURE_SIZE - 1) - texture_x;
    }
    else
    {
        texture_x = (int) (ray.pos.y / 2.0) % TEXTURE_SIZE;
        if (ray.angle > UP_DIR && ray.angle < DOWN_DIR) texture_x = (TEXTURE_SIZE - 1) - texture_x;
    }

    float distance_x_to_wall = fabs(ray.distance * cos(ray.angle));
    float distance_y_to_wall = fabs(ray.distance * sin(ray.angle));

    float distance_to_wall = fmax(distance_x_to_wall, distance_y_to_wall);

    if (distance_to_wall < RENDER_DISTANCE)
    {
        float shade = 1 - (distance_to_wall / RENDER_DISTANCE);

        // Draw walls
        for (int y = 0; y < line_h; y++)
        {
            int pixel_idx = ((int) (texture_y) * TEXTURE_SIZE + (int) texture_x) * 3;
            pixel_idx += ((ray.surface - 1) * TEXTURE_SIZE * TEXTURE_SIZE * 3);

            int red = ALL_TEXTURES[pixel_idx] * shade;
            int green = ALL_TEXTURES[pixel_idx + 1] * shade;
            int blue = ALL_TEXTURES[pixel_idx + 2] * shade;

            position_2D_t wall_pos = (position_2D_t) {ray.index * LINES_WIDTH + X_CORRECTION + VIEWPORT_X_OFFSET,
                                                       y + line_offset + VIEWPORT_Y_OFFSET};

            draw_point(wall_pos, LINES_WIDTH, (rgb_t) {red, green, blue});

            texture_y += texture_y_step;
        }
    }

    // Draw floors and ceilings

    float ray_angle_fix = cos(adjust_angle(player_angle - ray.angle));

    for (int y = line_h + line_offset; y < VIEWPORT_HEIGHT; y++)
    {
        float delta_y = y - (VIEWPORT_HEIGHT / 2.0);

        texture_x = (player_pos.x / 2) + cos(ray.angle) * FLOOR_CORRECTION * TEXTURE_SIZE / delta_y / ray_angle_fix;
        texture_y = (player_pos.y / 2) + sin(ray.angle) * FLOOR_CORRECTION * TEXTURE_SIZE / delta_y / ray_angle_fix;

        float distance = ((VIEWPORT_HEIGHT / 2.0) - delta_y) * (RENDER_CHUNK_SIZE / 3.75);

        if (distance < RENDER_DISTANCE)
        {
            float shade = 1 - distance / RENDER_DISTANCE;

            int pixel_idx = (((int) (texture_y) & (TEXTURE_SIZE - 1)) * TEXTURE_SIZE + ((int) (texture_x) & (TEXTURE_SIZE - 1))) * 3;

            int map_value = get_map_floor_at((position_2D_t) {texture_x / TEXTURE_SIZE, texture_y / TEXTURE_SIZE});

            if (map_value != AIR)
            {
                int floor_pixel_idx = pixel_idx + (map_value - 1) * TEXTURE_SIZE * TEXTURE_SIZE * 3;

                int red = ALL_TEXTURES[floor_pixel_idx] * shade;
                int green = ALL_TEXTURES[floor_pixel_idx + 1] * shade;
                int blue = ALL_TEXTURES[floor_pixel_idx + 2] * shade;

                position_2D_t floor_pos = (position_2D_t) {ray.index * LINES_WIDTH + X_CORRECTION + VIEWPORT_X_OFFSET,
                                                            y + VIEWPORT_Y_OFFSET};

                draw_point(floor_pos, LINES_WIDTH, (rgb_t) {red, green, blue});
            }
            map_value = get_map_ceiling_at((position_2D_t) {texture_x / TEXTURE_SIZE, texture_y / TEXTURE_SIZE});

            if (map_value != AIR)
            {
                int ceiling_pixel_idx = pixel_idx + (map_value - 1) * TEXTURE_SIZE * TEXTURE_SIZE * 3;

                int red = ALL_TEXTURES[ceiling_pixel_idx] * shade;
                int green = ALL_TEXTURES[ceiling_pixel_idx + 1] * shade;
                int blue = ALL_TEXTURES[ceiling_pixel_idx + 2] * shade;

                position_2D_t ceiling_pos = (position_2D_t) {ray.index * LINES_WIDTH + X_CORRECTION + VIEWPORT_X_OFFSET,
                                                              VIEWPORT_HEIGHT - CEILEING_CORRECTION - y + VIEWPORT_Y_OFFSET};
                
                draw_point(ceiling_pos, LINES_WIDTH, (rgb_t) {red, green, blue});
            }
        }
    }
}
