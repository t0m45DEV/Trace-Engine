#include "trc_file_manager.h"

#include "log.h"

#include <stdio.h>
#include <stdlib.h>

#define WRITE_MODE "wb"
#define READ_MODE  "rb"

const char* get_file_content(const char* filepath)
{
    FILE* file = fopen(filepath, READ_MODE);

    if (file == NULL)
    {
        log_error("There was a error opening %s", filepath);
        return NULL;
    }
    fseek(file, 0, SEEK_END);

    int file_len = ftell(file);
    rewind(file);

    char* content = malloc(file_len + 1);

    if (content == NULL)
    {
        log_error("There was an error allocating the buffer for %s", filepath);
        return NULL;
    }

    size_t read_size = fread(content, 1, file_len, file);

    if (read_size == 0)
    {
        log_error("There was an error reading %s", filepath);
        free(content);
        return NULL;
    }
    content[file_len] = '\0';

    fclose(file);

    return (const char*) content;
}

