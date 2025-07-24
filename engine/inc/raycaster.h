#ifndef _H_RAYCASTER
#define _H_RAYCASTER

#define FOV 60 /** Field of view (between 60 and 90 is okay, more than 90 warps the image) */

enum {
    NORTH_SOUTH_WALL,
    WEAST_EAST_WALL
};

/**
 * Returns the current ammount of rays for current FOV and resolution
 */
int get_ammount_of_rays(void);

/**
 * Cast the 2D top-down vision rays for the player and calls the 3D render
 */
void cast_rays(void);

/**
 * Initialize the raycaster
 *
 * @note Don't forget to use quit_raycaster after
 */
void init_raycaster(void);

/**
 * Safely delete and disable the raycaster
 */
void quit_raycaster(void);

#endif