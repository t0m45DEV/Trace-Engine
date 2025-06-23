#define STB_IMAGE_IMPLEMENTATION
#include "stb_lib/stb_image.h"

#include "../inc/textures.h"
#include <string.h>

#define WRITE_MODE "wb"

enum {
	IMG_PATH_ARG = 1,
	DEST_FILE_PATH_ARG,
	DEST_INFO_PATH_ARG
};

#define ARG_COUNT 4

#define HEADER_NAME "_H_TEXTURE_INFO"


int main(int argc, char* argv[])
{
    if (argc != ARG_COUNT)
    {
        printf("Error 01: Wrong use of arguments.\n");
    	printf("Example: %s path/to/image.png path/to/dest.ted path/to/dest_info.h\n", argv[0]);
    	exit(EXIT_FAILURE);
  	}

	char* img_path = argv[IMG_PATH_ARG];

	int width, height, channels;
	unsigned char* img = stbi_load(img_path, &width, &height, &channels, 0);

	if (img == NULL)
	{
	    printf("Error 02: Couldn't load the image.\n");
    	exit(EXIT_FAILURE);
	}
	int texture_size = width * width;
	int texture_count = height / width;
	int pixel_count = width * height;

	FILE* dest_header_file = fopen(argv[DEST_INFO_PATH_ARG], WRITE_MODE);

	fprintf(dest_header_file, "#ifndef %s\n", HEADER_NAME);
	fprintf(dest_header_file, "#define %s\n\n", HEADER_NAME);
	fprintf(dest_header_file, "#define TEXTURE_SIZE %i\n\n", width);
	fprintf(dest_header_file, "#define TEXTURES_ARR_SIZE %i\n\n", pixel_count);
	fprintf(dest_header_file, "\n#endif\n");
	fclose(dest_header_file);

	rgb_t pixel_arr[pixel_count];

	FILE* dest_file = fopen(argv[DEST_FILE_PATH_ARG], WRITE_MODE);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			unsigned char* pixel_offset = img + (j + i * width) * channels;
		
			unsigned char red   = pixel_offset[0];
			unsigned char green = pixel_offset[1];
			unsigned char blue  = pixel_offset[2];

			rgb_t pixel = {red, green, blue};

			pixel_arr[j + i * width] = pixel;
		}
	}
	fwrite(pixel_arr, sizeof(rgb_t) * pixel_count, 1, dest_file);
	fclose(dest_file);

	stbi_image_free(img);
	exit(EXIT_SUCCESS);
}
