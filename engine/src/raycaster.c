#include "raycaster.h"

#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#include "log.h"
#include "graphics.h"
#include "game_state.h"
#include "trigonometry.h"
#include "render.h"
#include "trc_camera.h"
#include "map.h"

#define NUM_THREADS 4

ray_t* rays;

pthread_t threads[NUM_THREADS];
int threads_ids[NUM_THREADS];

#define RATIO_ANGLE_RAYS (get_ammount_of_rays() / (float) FOV)   /** Relation between AMMOUNT_OF_RAYS and FOV, for making the right steps between every ray */

#define RAY_COLOR (rgb_t) {80, 80, 80} /** Color of the rays represented as a line */

int get_ammount_of_rays(void)
{
    return (FOV << 1) * get_actual_resolution();
}

void cast_rays_from_to(int start, int end)
{
    int count_of_hits;
    structures_t structure_hit;
    position_2D_t ray_pos;
    position_2D_t ray_offset = {0, 0};
    float distance_from_camera;
    float angle_cosine;

    position_2D_t camera_pos = get_camera_position();
    angle_t camera_angle = get_camera_angle();

    angle_t ray_angle = camera_angle - (DEG_TO_RAD(FOV / 2.0));
    ray_angle += (DEGREE / RATIO_ANGLE_RAYS) * start;
    ray_angle = adjust_angle(ray_angle);

    for (int ray_idx = start; ray_idx < end; ray_idx++)
    {
        /* Check horizontal lines */

        float distance_h = INFINITY;
        position_2D_t ray_H = {0, 0};
        structures_t surface_H = AIR;

        count_of_hits = 0;
        float aTan = -1 / tan(ray_angle);

        if (are_equals(ray_angle, RIGHT_DIR) || are_equals(ray_angle, LEFT_DIR)) /* If looking straight left or right */
        {
            ray_pos.x = camera_pos.x;
            ray_pos.y = camera_pos.y;

            count_of_hits = get_current_map_dimensions().y;
        }
        else if (ray_angle > LEFT_DIR) /* If looking down */
        {
            ray_pos.y = (((int) (camera_pos.y / MAP_CELL_SIZE)) * MAP_CELL_SIZE) - PRECISION;
            ray_pos.x = (camera_pos.y - ray_pos.y) * aTan + camera_pos.x;

            ray_offset.y = (-1) * MAP_CELL_SIZE;
            ray_offset.x = (-1) * ray_offset.y * aTan;
        }
        else if (ray_angle < LEFT_DIR) /* If looking up */
        {
            ray_pos.y = (((int) (camera_pos.y / MAP_CELL_SIZE)) * MAP_CELL_SIZE) + MAP_CELL_SIZE;
            ray_pos.x = (camera_pos.y - ray_pos.y) * aTan + camera_pos.x;

            ray_offset.y = MAP_CELL_SIZE;
            ray_offset.x = (-1) * ray_offset.y * aTan;
        }

        while (count_of_hits < get_current_map_dimensions().y)
        {
            structure_hit = get_map_wall_at(to_grid_pos(ray_pos));

            if (structure_hit != UNDEFINED && structure_hit != AIR) /* Hit a wall */
            {
                ray_H.x = ray_pos.x;
                ray_H.y = ray_pos.y;
                distance_h = distance_between(camera_pos, ray_pos);
                surface_H = structure_hit;

                count_of_hits = get_current_map_dimensions().y; /* End the loop */
            }
            else /* Check the next */
            {
                ray_pos.x += ray_offset.x;
                ray_pos.y += ray_offset.y;
                count_of_hits += 1;
            }
        }
        /* Check vertical lines */

        float distance_v = INFINITY;
        position_2D_t ray_V = {0, 0};
        structures_t surface_V = AIR;

        count_of_hits = 0;
        float nTan = (-1) * tan(ray_angle);

        if (are_equals(ray_angle, UP_DIR) || are_equals(ray_angle, DOWN_DIR)) /* If looking straight up or down */
        {
            ray_pos.x = camera_pos.x;
            ray_pos.y = camera_pos.y;

            count_of_hits = get_current_map_dimensions().x;
        }
        else if ((ray_angle > UP_DIR) && (ray_angle < DOWN_DIR)) /* If looking left */
        {
            ray_pos.x = (((int) (camera_pos.x / MAP_CELL_SIZE)) * MAP_CELL_SIZE) - PRECISION;
            ray_pos.y = (camera_pos.x - ray_pos.x) * nTan + camera_pos.y;

            ray_offset.x = (-1) * MAP_CELL_SIZE;
            ray_offset.y = (-1) * ray_offset.x * nTan;
        }
        else if ((ray_angle < UP_DIR) || (ray_angle > DOWN_DIR)) /* If looking right */
        {
            ray_pos.x = (((int) (camera_pos.x / MAP_CELL_SIZE)) * MAP_CELL_SIZE) + MAP_CELL_SIZE;
            ray_pos.y = (camera_pos.x - ray_pos.x) * nTan + camera_pos.y;

            ray_offset.x = MAP_CELL_SIZE;
            ray_offset.y = (-1) * ray_offset.x * nTan;
        }

        while (count_of_hits < get_current_map_dimensions().x)
        {
            structure_hit = get_map_wall_at(to_grid_pos(ray_pos));

            if (structure_hit != UNDEFINED && structure_hit != AIR) /* Hit a wall */
            {
                ray_V.x = ray_pos.x;
                ray_V.y = ray_pos.y;
                distance_v = distance_between(camera_pos, ray_pos);
                surface_V = structure_hit;

                count_of_hits = get_current_map_dimensions().x; /* End the loop */
            }
            else /* Check the next */
            {
                ray_pos.x += ray_offset.x;
                ray_pos.y += ray_offset.y;
                count_of_hits += 1;
            }
        }

        float actual_orientation;
        structures_t actual_surface;

        if (distance_h < distance_v)
        {
            ray_pos.x = ray_H.x;
            ray_pos.y = ray_H.y;
            distance_from_camera = distance_h;
            
            actual_orientation = NORTH_SOUTH_WALL;
            actual_surface = surface_H;
        }
        else
        {
            ray_pos.x = ray_V.x;
            ray_pos.y = ray_V.y;
            distance_from_camera = distance_v;

            actual_orientation = WEAST_EAST_WALL;
            actual_surface = surface_V;
        }

        angle_cosine = camera_angle - ray_angle;
        angle_cosine = adjust_angle(angle_cosine);

        distance_from_camera = distance_from_camera * cos(angle_cosine); /* Fix fisheye */
        rays[ray_idx] = (ray_t) {ray_idx, ray_pos, ray_angle, distance_from_camera, actual_surface, actual_orientation};

        ray_angle += (DEGREE / RATIO_ANGLE_RAYS);
        ray_angle = adjust_angle(ray_angle);
    }
}

void* multithreading_casting(void* arg)
{
    int thread_id = *(int*) arg;

    int first_ray = thread_id * (get_ammount_of_rays() / NUM_THREADS);
    int last_ray = first_ray + (get_ammount_of_rays() / NUM_THREADS);

    for (int i = first_ray; i < last_ray; i++)
    {
        cast_rays_from_to(first_ray, last_ray);
    }
    pthread_exit(NULL);
}

void cast_rays(void)
{
    for (int i = 0; i < NUM_THREADS; i++)
    {
        threads_ids[i] = i;
        pthread_create(&threads[i], NULL, multithreading_casting, &threads_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < get_ammount_of_rays(); i++)
    {
        if (!is_top_down_view_on())
        {
            render_line(rays[i]);
        }
        else
        {
            draw_line(get_camera_position(), rays[i].pos, 2, RAY_COLOR);
        }
    }
}

void init_raycaster(void)
{
    rays = (ray_t*) malloc(sizeof(ray_t) * get_ammount_of_rays());
    log_info("Raycaster initialized!");
}

void quit_raycaster(void)
{
    free(rays);
    log_info("Raycaster closed!");
}
