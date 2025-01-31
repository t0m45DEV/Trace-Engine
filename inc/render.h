#ifndef _H_RENDER
#define _H_RENDER

#include "window_display.h"
#include "all_textures.h"
#include "raycaster.h"
#include "map.h"

#define MAX_WALL_HEIGHT (WINDOW_HEIGHT)                       /**< A rename for WINDOW_HEIGHT, for easier code reading */
#define LINES_WIDTH ((int) (WINDOW_WIDTH / AMMOUNT_OF_RAYS))  /**< Ammount of pixels each ray will draw on screen      */
#define X_CORRECTION (LINES_WIDTH / 2)                        /**< Correction for X axis to get the screen centered    */
#define Y_CORRECTION (WINDOW_HEIGHT / 2)                      /**< Correction for Y axis to get the screen centered    */

#define DISTANCE_CORRECTION (((float) WINDOW_WIDTH) / ((float) WINDOW_HEIGHT)) /**< To see the walls square */

#define FLOOR_CORRECTION ((WINDOW_WIDTH / 2) - 4)  /**< The floor (and also the ceiling) stops sliding with this one */
#define CEILEING_CORRECTION (8 / resolution)       /**< The ceiling stops covering the walls */

/**
 * A ray is a line between the player and the closest wall in a certain angle
 */
typedef struct
{
    int index;             /**< Index of the ray, from 0 to AMMOUNT_OF_RAYS */
    position_2D_t pos;     /**< Position of the hit between the ray and the wall */
    float angle;             /**< Angle between the X axis and the ray, from the player position */
    float distance;        /**< Distance between the player and the wall that got hit by this ray */
    structures_t surface;  /**< The surface of the wall that got hit */
    float shade;           /**< The shade that the render will apply to the wall that got hit */
} ray_t;

/**
 *  Render a vertical line in the window, using the info from ray
 * 
 * @param ray A ray_t type, with the info of the wall, floor and ceiling to render
 */
void render_line(const ray_t ray);

#endif