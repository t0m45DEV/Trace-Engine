#define STB_IMAGE_IMPLEMENTATION
#include "stb_lib/stb_image.h"

#include <string.h>

#define WRITE_MODE "wb"

enum {
	IMG_PATH_ARG = 1,
	DEST_FILE_PATH_ARG,
	TEXTURE_SIZE_ARG,
	TEXTURE_MATRIX_ARG
};

#define ARG_COUNT 4

#define HEADER_DIR "inc/"
#define CODE_DIR   "src/"

#define HEADER_EXT ".h"
#define CODE_EXT   ".c"

int main(int argc, char* argv[])
{
    if (argc < ARG_COUNT)
    {
        printf("Error 01: Need arguments.\n");
    	printf("Example: %s path/to/image.png dest_file_name TEXTURE_SIZE_NAME TEXTURE_MATRIX_NAME\n", argv[0]);
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

	char dest_header_path[] = HEADER_DIR;
	strcat(dest_header_path, argv[DEST_FILE_PATH_ARG]);
	strcat(dest_header_path, HEADER_EXT);
	
	FILE* dest_header_file = fopen(dest_header_path, WRITE_MODE);

	fprintf(dest_header_file, "#ifndef _H_%s\n", argv[TEXTURE_MATRIX_ARG]);
	fprintf(dest_header_file, "#define _H_%s\n\n", argv[TEXTURE_MATRIX_ARG]);
	fprintf(dest_header_file, "#define %s %i\n\n", argv[TEXTURE_SIZE_ARG], width);
	fprintf(dest_header_file, "extern const int %s[];\n", argv[TEXTURE_MATRIX_ARG]);
	fprintf(dest_header_file, "\n#endif\n");
	fclose(dest_header_file);

	char dest_code_path[] = CODE_DIR;
	strcat(dest_code_path, argv[DEST_FILE_PATH_ARG]);
	strcat(dest_code_path, CODE_EXT);

	FILE* dest_code_file = fopen(dest_code_path, WRITE_MODE);
	
	fprintf(dest_code_file, "#include \"%s.h\"\n", argv[DEST_FILE_PATH_ARG]);
	fprintf(dest_code_file, "\nconst int %s[] =\n{\n", argv[TEXTURE_MATRIX_ARG]);

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
	exit(EXIT_SUCCESS);
}
