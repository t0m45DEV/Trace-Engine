#include "window_display.h"

#include "pop_up_windows.h"
#include "game_state.h"
#include "raycaster.h"
#include "player.h"
#include "map.h"

/** V-sync modes */

#define V_SYNC_OFF    0  /** Immediate update from frame to frame */
#define V_SYNC_ON     1  /** Updates synchronized with the vertical retrace */
#define V_SYNC_ADAPT -1  /** Adaptive V-sync */

resolutions_t resolution = LOW_RESOLUTION;

int get_actual_resolution(void)
{
    return resolution;
}

void set_actual_resolution(resolutions_t new_resolution)
{
    resolution = new_resolution;
}

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
        nk_sdl_render(NK_ANTI_ALIASING_ON);
    }
}
