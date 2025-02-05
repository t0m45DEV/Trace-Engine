#ifndef _H_RAYCASTER
#define _H_RAYCASTER

#include <stdbool.h>

#include "player.h"
#include "map.h"
#include "trigonometry.h"
#include "render.h"

#define FOV 60                                     /**< Field of view (between 60 and 90 is okay, more than 90 warps the image)                */
#define AMMOUNT_OF_RAYS ((FOV * 2) * resolution)   /**< Ammount of rays per degree of FOV (more rays means more image quality, normal is 2)    */
#define RATIO_ANGLE_RAYS (AMMOUNT_OF_RAYS / FOV)   /**< Relation between AMMOUNT_OF_RAYS and FOV, for making the right steps between every ray */

#define NORTH_SOUTH_WALL 0     /**< The North / South orientation of the wall  */
#define WEAST_EAST_WALL  1     /**< The Weast / East orientation of the wall */

#define RAY_COLOR (rgb_t) {0.3, 0.3, 0.3} /**< Color of the rays represented as a line */

/**
 * Cast the 2D top-down vision rays for the player and calls the 3D render
 */
void cast_rays(void);

#endif