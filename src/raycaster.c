#include "raycaster.h"

void cast_rays(bool debug_view)
{
    int count_of_hits;
    position_2D map_ray;
    int ray_in_map;
    position_2D ray_pos;
    position_2D ray_offset;
    float distance_from_player;
    float angle_cosine;

    float ray_angle = player.angle - DEGREE * (ANGLE_OF_VISION / 2);
    ray_angle = adjust_angle(ray_angle);

    for (int ray = 0; ray < AMMOUNT_OF_RAYS; ray++)
    {
        // Check horizontal lines

        float distance_h = INT32_MAX;
        position_2D ray_H;

        count_of_hits = 0;
        float aTan = -1 / tan(ray_angle);

        if ((ray_angle == 0) || (ray_angle == PI)) // If looking straight left or right
        {
            ray_pos.x = player.pos.x;
            ray_pos.y = player.pos.y;

            count_of_hits = MAP_Y_SIZE;
        }
        else if (ray_angle > PI) // If looking down
        {
            ray_pos.y = (((int) player.pos.y / MAP_CELL_SIZE) * MAP_CELL_SIZE) - PRECISION;
            ray_pos.x = (player.pos.y - ray_pos.y) * aTan + player.pos.x;

            ray_offset.y = (-1) * MAP_CELL_SIZE;
            ray_offset.x = (-1) * ray_offset.y * aTan;
        }
        else if (ray_angle < PI) // If looking up
        {
            ray_pos.y = (((int) player.pos.y / MAP_CELL_SIZE) * MAP_CELL_SIZE) + MAP_CELL_SIZE;
            ray_pos.x = (player.pos.y - ray_pos.y) * aTan + player.pos.x;

            ray_offset.y = MAP_CELL_SIZE;
            ray_offset.x = (-1) * ray_offset.y * aTan;
        }

        while (count_of_hits < MAP_Y_SIZE)
        {
            map_ray.x = (int) (ray_pos.x / MAP_CELL_SIZE);
            map_ray.y = (int) (ray_pos.y / MAP_CELL_SIZE);
            ray_in_map = REAL_POS_TO_GRID_POS(map_ray.x, map_ray.y);

            if ((ray_in_map > 0) && (ray_in_map < (MAP_X_SIZE * MAP_Y_SIZE)) && (map[ray_in_map] != AIR)) // Hit a wall
            {
                ray_H.x = ray_pos.x;
                ray_H.y = ray_pos.y;
                distance_h = distance_between(player.pos, ray_pos);

                count_of_hits = MAP_Y_SIZE;
            }
            else // Check the next 
            {
                ray_pos.x += ray_offset.x;
                ray_pos.y += ray_offset.y;
                count_of_hits += 1;
            }
        }

        // Check vertical lines

        float distance_v = INT32_MAX;
        position_2D ray_V;

        count_of_hits = 0;
        float nTan = (-1) * tan(ray_angle);

        if ((ray_angle == UP_DIR) || (ray_angle == DOWN_DIR)) // If looking straight up or down
        {
            ray_pos.x = player.pos.x;
            ray_pos.y = player.pos.y;

            count_of_hits = MAP_X_SIZE;
        }
        else if ((ray_angle > UP_DIR) && (ray_angle < DOWN_DIR)) // If looking left
        {
            ray_pos.x = (((int) player.pos.x / MAP_CELL_SIZE) * MAP_CELL_SIZE) - PRECISION;
            ray_pos.y = (player.pos.x - ray_pos.x) * nTan + player.pos.y;

            ray_offset.x = (-1) * MAP_CELL_SIZE;
            ray_offset.y = (-1) * ray_offset.x * nTan;
        }
        else if ((ray_angle < UP_DIR) || (ray_angle > DOWN_DIR)) // If looking right
        {
            ray_pos.x = (((int) player.pos.x / MAP_CELL_SIZE) * MAP_CELL_SIZE) + MAP_CELL_SIZE;
            ray_pos.y = (player.pos.x - ray_pos.x) * nTan + player.pos.y;

            ray_offset.x = MAP_CELL_SIZE;
            ray_offset.y = (-1) * ray_offset.x * nTan;
        }

        while (count_of_hits < MAP_X_SIZE)
        {
            map_ray.x = (int) (ray_pos.x / MAP_CELL_SIZE);
            map_ray.y = (int) (ray_pos.y / MAP_CELL_SIZE);
            ray_in_map = REAL_POS_TO_GRID_POS(map_ray.x, map_ray.y);

            if ((ray_in_map > 0) && (ray_in_map < (MAP_X_SIZE * MAP_Y_SIZE)) && (map[ray_in_map] != AIR)) // Hit a wall
            {
                ray_V.x = ray_pos.x;
                ray_V.y = ray_pos.y;
                distance_v = distance_between(player.pos, ray_pos);

                count_of_hits = MAP_X_SIZE;
            }
            else // Check the next 
            {
                ray_pos.x += ray_offset.x;
                ray_pos.y += ray_offset.y;
                count_of_hits += 1;
            }
        }

        if (distance_h < distance_v)
        {
            ray_pos.x = ray_H.x;
            ray_pos.y = ray_H.y;
            distance_from_player = distance_h;
            glColor3f(0.9, 0, 0);
        }
        else
        {
            ray_pos.x = ray_V.x;
            ray_pos.y = ray_V.y;
            distance_from_player = distance_v;
            glColor3f(0.7, 0, 0);
        }

        if (!debug_view)
        {
            angle_cosine = player.angle - ray_angle;
            angle_cosine = adjust_angle(angle_cosine);

            distance_from_player = distance_from_player * cos(angle_cosine); // Fix fisheye
            render_line(distance_from_player, ray);
        }

        if (debug_view)
        {
            glLineWidth(2);
            glBegin(GL_LINES);
            glVertex2i(player.pos.x, player.pos.y);
            glVertex2i(ray_pos.x, ray_pos.y);
            glEnd();
        }

        ray_angle += (DEGREE / RATIO_ANGLE_RAYS);
        ray_angle = adjust_angle(ray_angle);
    }
}
