#include <stdbool.h>

/** The title to be shown on the top of the window */
#define WINDOW_TITLE "Tom's 3D Engine"

#define WINDOW_HEIGHT (VIEWPORT_HEIGHT + (VIEWPORT_Y_OFFSET * 2))
#define WINDOW_WIDTH  (VIEWPORT_WIDTH + (VIEWPORT_X_OFFSET * 2))

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <GL/gl.h>

#include "pop_up_windows.h"

#include "log.h"
#include "raycaster.h"
#include "window_display.h"
#include "game_state.h"
#include "delta_time.h"
#include "loop.h"
#include "fps_counter.h"
#include "map.h"
#include "textures.h"

#define SDL_INIT_ENGINE (SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS)

bool init_GL(void)
{
    // Initialize projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Check for errors
    if (glGetError() != GL_NO_ERROR)
    {
        log_error("Error initializing OpenGL projection matrix!");
        return false;
    }
    log_info("OpenGL projection matrix initialized!");
    glOrtho(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0, -1.0, 1.0);

    // Initialize modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Check for errors
    if (glGetError() != GL_NO_ERROR)
    {
        log_error("Error initializing OpenGL modelview matrix!");
        return false;
    }
    log_info("OpenGL modelview matrix initialized!");
    return true;
}

int main(void)
{
    load_textures();

    init_game_state();
    load_level(FIRST_LEVEL);

    /* Try to initialize SDL */
    if (SDL_Init(SDL_INIT_ENGINE) != 0)
    {
        log_error("Error initializing SDL Error: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    log_info("SDL initialized.");
    /* To use OpenGL legacy functions */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    
    SDL_Window* window = create_window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!init_GL())
    {
        log_error("Unable to initialize OpenGL");
        exit(EXIT_FAILURE);
    }
    log_info("OpenGL fully initialized!");
    set_background_color(BACKGROUND_COLOR);

    nk_ctx = nk_sdl_init(window);
    init_nk_windows(nk_ctx);

    init_raycaster();
    init_delta_time_counter();
    init_fps_counter();

    while (is_game_running())
    {
        main_loop(window);
    }
    quit_raycaster();
    nk_sdl_shutdown();
    SDL_DestroyWindow(window);
    log_info("SDL window destroyed!");
    log_info("Good bye :)");

    exit(EXIT_SUCCESS);
}
