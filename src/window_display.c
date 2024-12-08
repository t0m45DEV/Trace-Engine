#include "window_display.h"

int resolution = LOW_RESOLUTION;

bool debug_2D_view = false;

float delta_time = 0;

SDL_Window* create_window(const char* title, int width, int height)
{
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_GLContext* context = SDL_GL_CreateContext(window);
  
    if (!context)
    {
        printf("Context could not be created! SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
  
    if (SDL_GL_SetSwapInterval(1) < 0)
    {
        printf("Unable to set VSync! SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return window;
}

void set_background_color(rgb_t color)
{
    glClearColor(color.r, color.g, color.b, 1);
}

void render_screen(void)
{
    if (debug_2D_view) draw_map_2D();
    cast_rays();
    if (debug_2D_view) draw_player();
}
