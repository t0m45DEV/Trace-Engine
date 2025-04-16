#include <stdio.h>
#include <stdbool.h>

/** The title to be shown on the top of the window */
#define WINDOW_TITLE "Tom's 3D Engine"

#define WINDOW_HEIGHT (VIEWPORT_HEIGHT + (VIEWPORT_Y_OFFSET * 2))
#define WINDOW_WIDTH  (VIEWPORT_WIDTH + (VIEWPORT_X_OFFSET * 2))

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <GL/gl.h>

#include "pop_up_windows.h"

#include "window_display.h"
#include "game_state.h"
#include "delta_time.h"
#include "loop.h"
#include "fps_counter.h"
#include "map.h"

#define SDL_INIT_ENGINE (SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS)

bool init_GL(void)
{
    // Initialize projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Check for errors
    if (glGetError() != GL_NO_ERROR)
    {
        printf("Error initializing OpenGL projection matrix!\n");
        return false;
    }
    glOrtho(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0, -1.0, 1.0);

    // Initialize modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Check for errors
    if (glGetError() != GL_NO_ERROR)
    {
        printf("Error initializing OpenGL modelview matrix!\n");
        return false;
    }
    return true;
}

int main(void)
{
    init_game_state();
    load_level(FIRST_LEVEL);

    /* Try to initialize SDL */
    if (SDL_Init(SDL_INIT_ENGINE) != 0)
    {
        printf("Error initializing SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    /* To use OpenGL legacy functions */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    
    SDL_Window* window = create_window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!init_GL())
    {
        printf("Unable to initialize OpenGL\n");
        exit(EXIT_FAILURE);
    }
    set_background_color(BACKGROUND_COLOR);

    nk_ctx = nk_sdl_init(window);
    init_nk_windows(nk_ctx);

    // Load the default font for Nuklear
    struct nk_font_atlas *atlas;
    nk_sdl_font_stash_begin(&atlas);
    nk_sdl_font_stash_end();

    //engine_timer_t animation_timer = create_timer(0.3);
    //start_timer(&animation_timer);

    init_delta_time_counter();
    init_fps_counter();

    while (is_game_running())
    {
        main_loop(window);
    }
    nk_sdl_shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    exit(EXIT_SUCCESS);
}
