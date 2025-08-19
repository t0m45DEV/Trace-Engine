#ifndef _H_ALL_TEXTURES
#define _H_ALL_TEXTURES

#include "graphics.h"
#include "map.h"

/**
 * Loads the textures into engine structures (for faster performance)
 */
void load_textures(void);

/**
 * Returns the size of the textures being used
 * 
 * @note All the textures are square, so it only returns the length of one side
 */
int get_texture_size(void);

/**
 * Given an structure and a texture position, it returns the RGB info of the pixel in that position
 */
rgb_t get_texture_pixel(structures_t structure, trc_world_position_t pixel_pos);

/**
 * Given an RGB and a shade, returns the same pixel but modified with the shade
 */
rgb_t apply_shade(rgb_t original_pixel, float shade);

#endif
