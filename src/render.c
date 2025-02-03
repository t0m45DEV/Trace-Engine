#include "render.h"

#include <stdio.h>

void render_line(const ray_t ray)
{
    float line_h = ((MAP_CELL_SIZE * WINDOW_HEIGHT) / ray.distance) * DISTANCE_CORRECTION;
    
    float texture_y_step = TEXTURE_SIZE / (float) line_h;
    float texture_y_offset = 0;
    
    if (line_h > MAX_WALL_HEIGHT)
    {
        texture_y_offset = (line_h - WINDOW_HEIGHT) / 2;
        line_h = MAX_WALL_HEIGHT;
    }

    float line_offset = (Y_CORRECTION) - line_h / 2;
    float texture_y = (texture_y_offset * texture_y_step) - 1;
    float texture_x;

    if (fabs(ray.wall_orientation - NORTH_SOUTH_WALL) < PRECISION)
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

            int red = ALL_TEXTURES[pixel_idx];
            int green = ALL_TEXTURES[pixel_idx + 1];
            int blue = ALL_TEXTURES[pixel_idx + 2];

            glPointSize(LINES_WIDTH);
            glColor3ub(red * shade, green * shade, blue * shade);
            glBegin(GL_POINTS);
            glVertex2i(ray.index * LINES_WIDTH + X_CORRECTION, y + line_offset);
            glEnd();
            texture_y += texture_y_step;
        }
    }

    // Draw floors and ceilings

    float ray_angle_fix = cos(adjust_angle(player.angle - ray.angle));

    for (int y = line_h + line_offset; y < WINDOW_HEIGHT; y++)
    {
        float delta_y = y - (WINDOW_HEIGHT / 2.0);

        texture_x = (player.pos.x / 2) + cos(ray.angle) * FLOOR_CORRECTION * TEXTURE_SIZE / delta_y / ray_angle_fix;
        texture_y = (player.pos.y / 2) + sin(ray.angle) * FLOOR_CORRECTION * TEXTURE_SIZE / delta_y / ray_angle_fix;

        float distance = ((WINDOW_HEIGHT / 2.0) - delta_y) * (RENDER_CHUNK_SIZE / 3.75);

        if (distance < RENDER_DISTANCE)
        {
            float shade = 1 - distance / RENDER_DISTANCE;

            int pixel_idx = (((int) (texture_y) & (TEXTURE_SIZE - 1)) * TEXTURE_SIZE + ((int) (texture_x) & (TEXTURE_SIZE - 1))) * 3;

            int map_value = map_f[REAL_POS_TO_GRID_POS(texture_x / TEXTURE_SIZE, texture_y / TEXTURE_SIZE)];

            if (map_value != AIR)
            {
                int floor_pixel_idx = pixel_idx + (map_value - 1) * TEXTURE_SIZE * TEXTURE_SIZE * 3;

                int red = ALL_TEXTURES[floor_pixel_idx];
                int green = ALL_TEXTURES[floor_pixel_idx + 1];
                int blue = ALL_TEXTURES[floor_pixel_idx + 2];

                glPointSize(LINES_WIDTH);
                glColor3ub(red * shade, green * shade, blue * shade);
                glBegin(GL_POINTS);
                glVertex2i(ray.index * LINES_WIDTH + X_CORRECTION, y);
                glEnd();
            }

            map_value = map_c[REAL_POS_TO_GRID_POS(texture_x / TEXTURE_SIZE, texture_y / TEXTURE_SIZE)];

            if (map_value != AIR)
            {
                int ceiling_pixel_idx = pixel_idx + (map_value - 1) * TEXTURE_SIZE * TEXTURE_SIZE * 3;

                int red = ALL_TEXTURES[ceiling_pixel_idx];
                int green = ALL_TEXTURES[ceiling_pixel_idx + 1];
                int blue = ALL_TEXTURES[ceiling_pixel_idx + 2];
                
                glColor3ub(red * shade, green * shade, blue * shade);
                glPointSize(LINES_WIDTH);
                glBegin(GL_POINTS);
                glVertex2i(ray.index * LINES_WIDTH + X_CORRECTION, WINDOW_HEIGHT - CEILEING_CORRECTION - y);
                glEnd();
            }
        }
    }
}
