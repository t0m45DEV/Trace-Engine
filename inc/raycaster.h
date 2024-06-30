#ifndef _H_RAYCASTER
#define _H_RAYCASTER

#include <GL/glut.h>
#include <stdbool.h>

#include "player.h"
#include "map.h"
#include "trigonometry.h"
#include "3D_render.h"

#define FOV 60
#define AMMOUNT_OF_RAYS ((FOV * 2) * resolution)
#define RATIO_ANGLE_RAYS (AMMOUNT_OF_RAYS / FOV)

#define PRECISION 0.0001

#define LIGHT_SHADE 0.9
#define DARK_SHADE 0.7

/*
    Cast the 2D top-down vision rays for the player and calls the 3D render
*/
void cast_rays(bool debug_view);

#endif