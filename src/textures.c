#include "textures.h"

#include <stdio.h>
#include <assert.h>

#include "textures_info.h"

#define TEXTURE_FILE_PATH "./data/structures.ted"
#define READ_MODE "r"

rgb_t ALL_TEXTURES[TEXTURES_ARR_SIZE];

void load_textures(void)
{
    FILE* textures_file = fopen(TEXTURE_FILE_PATH, READ_MODE);

    size_t read_out = fread(ALL_TEXTURES, sizeof(rgb_t) * TEXTURES_ARR_SIZE, 1, textures_file);
    assert(read_out > 0);

    fclose(textures_file);
}

int get_texture_size(void)
{
    return TEXTURE_SIZE;
}

rgb_t get_texture_pixel(structures_t structure, position_2D_t pixel_pos)
{
    //printf("Hello there\n");
    int pixel_id = ((int) (pixel_pos.y) * TEXTURE_SIZE + (int) pixel_pos.x);
    pixel_id += ((structure - 1) * TEXTURE_SIZE * TEXTURE_SIZE);

    return ALL_TEXTURES[pixel_id];
}

rgb_t apply_shade(rgb_t original_pixel, float shade)
{
    rgb_t new_pixel = {
        original_pixel.r * shade,
        original_pixel.g * shade,
        original_pixel.b * shade
    };

    return new_pixel;
}
