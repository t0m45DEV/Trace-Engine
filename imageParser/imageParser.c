#include <stdio.h>
#include <stdlib.h>

#define DEBUG_INT(x) printf("%s: %i\n", #x, (x));

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define WRITE_MODE "wb"

#define IMG_PATH_ARG 1
#define DEST_HEADER_PATH_ARG 2
#define DEST_CODE_PATH_ARG 3
#define TEXTURE_SIZE_ARG 4
#define TEXTURE_MATRIX_ARG 5

int main(int argc, char* argv[])
{
    if (argc < 5)
    {
        printf("Error 01: Need arguments.\n");
    	printf("Example: %s path/to/image.png path/to/dest.h path/to/dest.c TEXTURE_SIZE_NAME TEXTURE_MATRIX_NAME\n", argv[0]);
    	return EXIT_FAILURE;
  	}

	char* img_path = argv[IMG_PATH_ARG];

	int width, height, channels;
	unsigned char* img = stbi_load(img_path, &width, &height, &channels, 0);

	if (img == NULL)
	{
	    printf("Error 02: Couldn't load the image.\n");
    	return EXIT_FAILURE;
	}

	char* dest_header_path = argv[DEST_HEADER_PATH_ARG];
	FILE* dest_header_file = fopen(dest_header_path, WRITE_MODE);

	fprintf(dest_header_file, "#ifndef _H_%s\n", argv[TEXTURE_MATRIX_ARG]);
	fprintf(dest_header_file, "#define _H_%s\n\n", argv[TEXTURE_MATRIX_ARG]);
	fprintf(dest_header_file, "#define %s %i\n\n", argv[TEXTURE_SIZE_ARG], width);
	fprintf(dest_header_file, "extern int %s[];\n", argv[TEXTURE_MATRIX_ARG]);
	fprintf(dest_header_file, "\n#endif\n");
	fclose(dest_header_file);

	char* dest_code_path = argv[DEST_CODE_PATH_ARG];
	FILE* dest_code_file = fopen(dest_code_path, WRITE_MODE);
	
	fprintf(dest_code_file, "\nint %s[] =\n{\n", argv[TEXTURE_MATRIX_ARG]);


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			unsigned char* pixel_offset = img + (j + i * width) * channels;
		
			unsigned char red   = pixel_offset[0];
			unsigned char green = pixel_offset[1];
			unsigned char blue  = pixel_offset[2];
	
			fprintf(dest_code_file, "%u, %u, %u,\n", red, green, blue);
		}
	}
	fprintf(dest_code_file, "};\n");
	fclose(dest_code_file);

	stbi_image_free(img);
	return EXIT_SUCCESS;
}
