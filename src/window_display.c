#include "window_display.h"

int resolution = LOW_RESOLUTION;

SDL_Window* window = NULL;

SDL_Window* create_window(const char* title, const int width, const int height)
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
  
    if (SDL_GL_SetSwapInterval(V_SYNC_ON) != 0)
    {
        printf("Unable to set VSync! SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return window;
}

void set_background_color(const rgb_t color)
{
    glClearColor(color.r, color.g, color.b, 1);
}

void render_screen(void)
{
    switch (get_current_scene())
    {
        case MAIN_MENU_SCENE:
            break;
        
        case GAME_SCENE:
            if (is_top_down_view_on()) draw_map_2D();
            cast_rays();
            if (is_top_down_view_on()) draw_player();
            break;

        default:
            break;
    }
    if (is_debug_console_on())
    {
        show_debug_console();

        #if defined(__EMSCRIPTEN__) // If the game will run in the web
        {
            nk_sdl_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_MEMORY, MAX_ELEMENT_MEMORY);
        }
        #else // If the game will run locally
        {
            nk_sdl_render(NK_ANTI_ALIASING_ON);
        }
        #endif
    }
}
