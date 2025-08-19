#include "textures.h"

#include <stdio.h>

#include "textures_info.h"
#include "log.h"

#define TEXTURE_FILE_PATH "engine/data/structures.ted"
#define READ_MODE "r"

#define TEXTURES_ARR_SIZE (TEXTURE_SIZE * TEXTURE_SIZE * TEXTURE_COUNT)

rgb_t ALL_TEXTURES[TEXTURES_ARR_SIZE];

void load_textures(void)
{
    FILE* textures_file = fopen(TEXTURE_FILE_PATH, READ_MODE);

    size_t read_out = fread(ALL_TEXTURES, sizeof(rgb_t) * TEXTURES_ARR_SIZE, 1, textures_file);
    
    if (read_out <= 0)
    {
        log_error("There was an error loading the textures!");
    }
    log_info("Textures loaded!");

    fclose(textures_file);
}

int get_texture_size(void)
{
    return TEXTURE_SIZE;
}

rgb_t get_texture_pixel(structures_t structure, trc_world_position_t pixel_pos)
{
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
