#include <GL/glut.h>
#include <math.h>

#include "raycaster.h"
#include "player.h"
#include "map.h"
#include "trigonometry.h"


void draw_rays(void)
{
    int dof;
    int ray_map_x;
    int ray_map_y;
    int ray_in_map;
    float ray_x;
    float ray_y;
    float x_offset;
    float y_offset;

    float ray_angle = player.angle;

    for (int ray = 0; ray < AMMOUNT_OF_RAYS; ray++)
    {
        // Check horizontal lines

        dof = 0;
        float aTan = -1 / tan(ray_angle);

        if ((ray_angle == 0) || (ray_angle == PI)) // If looking straight left or right
        {
            ray_x = player.x_pos;
            ray_y = player.y_pos;

            dof = MAP_Y_SIZE;
        }
        else if (ray_angle > PI) // If looking down
        {
            ray_y = (((int) player.y_pos / MAP_CELL_SIZE) * MAP_CELL_SIZE) - PRECISION;
            ray_x = (player.y_pos - ray_y) * aTan + player.x_pos;

            y_offset = (-1) * MAP_CELL_SIZE;
            x_offset = (-1) * y_offset * aTan;
        }
        else if (ray_angle < PI) // If looking up
        {
            ray_y = (((int) player.y_pos / MAP_CELL_SIZE) * MAP_CELL_SIZE) + MAP_CELL_SIZE;
            ray_x = (player.y_pos - ray_y) * aTan + player.x_pos;

            y_offset = MAP_CELL_SIZE;
            x_offset = (-1) * y_offset * aTan;
        }

        while (dof < MAP_Y_SIZE)
        {
            ray_map_x = (int) (ray_x / MAP_CELL_SIZE);
            ray_map_y = (int) (ray_y / MAP_CELL_SIZE);
            ray_in_map = ray_map_y * MAP_X_SIZE + ray_map_x;

            if ((ray_in_map > 0) && (ray_in_map < (MAP_X_SIZE * MAP_Y_SIZE)) && (map[ray_in_map] == 1)) // Hit a wall
            {
                dof = MAP_Y_SIZE;
            }
            else // Check the next 
            {
                ray_x += x_offset;
                ray_y += y_offset;
                dof += 1;
            }
        }

        glColor3f(1, 0, 0);
        glLineWidth(10);
        glBegin(GL_LINES);
        glVertex2i(player.x_pos, player.y_pos);
        glVertex2i(ray_x, ray_y);
        glEnd();

        // Check vertical lines

        dof = 0;
        float nTan = (-1) * tan(ray_angle);

        if ((ray_angle == UP_DIR) || (ray_angle == DOWN_DIR)) // If looking straight up or down
        {
            ray_x = player.x_pos;
            ray_y = player.y_pos;

            dof = MAP_X_SIZE;
        }
        else if ((ray_angle > UP_DIR) && (ray_angle < DOWN_DIR)) // If looking left
        {
            ray_x = (((int) player.x_pos / MAP_CELL_SIZE) * MAP_CELL_SIZE) - PRECISION;
            ray_y = (player.x_pos - ray_x) * nTan + player.y_pos;

            x_offset = (-1) * MAP_CELL_SIZE;
            y_offset = (-1) * x_offset * nTan;
        }
        else if ((ray_angle < UP_DIR) || (ray_angle > DOWN_DIR)) // If looking right
        {
            ray_x = (((int) player.x_pos / MAP_CELL_SIZE) * MAP_CELL_SIZE) + MAP_CELL_SIZE;
            ray_y = (player.x_pos - ray_x) * nTan + player.y_pos;

            x_offset = MAP_CELL_SIZE;
            y_offset = (-1) * x_offset * nTan;
        }

        while (dof < MAP_X_SIZE)
        {
            ray_map_x = (int) (ray_x / MAP_CELL_SIZE);
            ray_map_y = (int) (ray_y / MAP_CELL_SIZE);
            ray_in_map = ray_map_y * MAP_X_SIZE + ray_map_x;

            if ((ray_in_map > 0) && (ray_in_map < (MAP_X_SIZE * MAP_Y_SIZE)) && (map[ray_in_map] == 1)) // Hit a wall
            {
                dof = MAP_Y_SIZE;
            }
            else // Check the next 
            {
                ray_x += x_offset;
                ray_y += y_offset;
                dof += 1;
            }
        }

        glColor3f(0, 1, 0);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2i(player.x_pos, player.y_pos);
        glVertex2i(ray_x, ray_y);
        glEnd();
    }
}
