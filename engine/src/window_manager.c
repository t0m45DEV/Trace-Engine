#include "window_manager.h"

#include "log.h"

#include "pop_up_windows.h"
#include "graphics.h"

#include <stdbool.h>

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "glad/glad.h"

SDL_Window* engine_window;

/** V-sync modes */

#define V_SYNC_OFF    0  /** Immediate update from frame to frame */
#define V_SYNC_ON     1  /** Updates synchronized with the vertical retrace */
#define V_SYNC_ADAPT -1  /** Adaptive V-sync */

#define SDL_INIT_ENGINE (SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS)

bool init_GL(int window_width, int window_height)
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
    glOrtho(0.0, window_width, window_height, 0.0, -1.0, 1.0);

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

void init_glad(SDL_Window* window)
{
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);

    if (!gl_context)
    {
        log_error("Failed to create OpenGL context: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        log_error("Failed to initialize GLAD");
        exit(EXIT_FAILURE);
    }
    log_info("GLAD initialized successfully");
    log_info("OpenGL version: %s", glGetString(GL_VERSION));
}

void init_SLD(void)
{
    /* Try to initialize SDL */
    if (SDL_Init(SDL_INIT_ENGINE) != 0)
    {
        log_error("Error initializing SDL Error: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    log_info("SDL initialized.");
    /* To use OpenGL legacy functions */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
}

void create_window(const char* title, const int width, const int height)
{
    init_SLD();

    engine_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (engine_window == NULL)
    {
        log_error("Window could not be created! SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    log_info("SDL window created!");

    SDL_GLContext* context = SDL_GL_CreateContext(engine_window);
  
    if (!context)
    {
        log_error("Context could not be created! SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    log_info("SDL context created!");
  
    if (SDL_GL_SetSwapInterval(V_SYNC_ON) != 0)
    {
        log_error("Unable to set VSync! SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    log_info("VSync activated!");
    
    init_glad(engine_window);

    if (!init_GL(width, height))
    {
        log_error("Unable to initialize OpenGL");
        exit(EXIT_FAILURE);
    }
    log_info("OpenGL fully initialized!");

    set_background_color(BACKGROUND_COLOR);

    init_nk_windows(engine_window);
}

void update_window(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    render_screen();
}

void swap_window_buffers(void)
{
    SDL_GL_SwapWindow(engine_window);
}

void destroy_window(void)
{
    SDL_DestroyWindow(engine_window);
    log_info("SDL window destroyed!");
}
