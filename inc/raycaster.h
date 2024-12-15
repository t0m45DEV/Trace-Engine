#ifndef _H_RAYCASTER
#define _H_RAYCASTER

#include <stdbool.h>

#include "player.h"
#include "map.h"
#include "trigonometry.h"
#include "3D_render.h"

#define FOV 60                                     /**< Field of view (between 60 and 90 is okay, more than 90 warps the image)                */
#define AMMOUNT_OF_RAYS ((FOV * 2) * resolution)   /**< Ammount of rays per degree of FOV (more rays means more image quality, normal is 2)    */
#define RATIO_ANGLE_RAYS (AMMOUNT_OF_RAYS / FOV)   /**< Relation between AMMOUNT_OF_RAYS and FOV, for making the right steps between every ray */

#define PRECISION 0.0001   /**< To pass from int to float and don't loose precision */

#define LIGHT_SHADE 0.9    /**< The shade of the "lighted" objects (in reality there no such a thing as light in this engine)  */
#define DARK_SHADE 0.6     /**< The shade of the "darkened" objects (in reality there no such a thing as light in this engine) */

/**
 * Cast the 2D top-down vision rays for the player and calls the 3D render
 */
void cast_rays(void);

#endif