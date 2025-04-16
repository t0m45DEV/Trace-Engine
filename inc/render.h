#ifndef _H_RENDER
#define _H_RENDER

#include "map.h"

/**
 * A ray is a line between the player and the closest wall in a certain angle
 */
typedef struct
{
    int index;              /** Index of the ray, from 0 to AMMOUNT_OF_RAYS */
    position_2D_t pos;      /** Position of the hit between the ray and the wall */
    float angle;            /** Angle between the X axis and the ray, from the player position */
    float distance;         /** Distance between the player and the wall that got hit by this ray */
    structures_t surface;   /** The surface of the wall that got hit */
    float wall_orientation; /** The orientation of the wall (north-south or west-east) */
} ray_t;

/**
 *  Render a vertical line in the window, using the info from ray
 * 
 * @param ray A ray_t type, with the info of the wall, floor and ceiling to render
 */
void render_line(const ray_t ray);

#endif