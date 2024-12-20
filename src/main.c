#include <stdio.h>
#include <stdbool.h>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <GL/gl.h>

#include "window_display.h"
#include "world.h"
#include "player.h"
#include "timer.h"

bool initGL(void)
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
    load_level(FIRST_LEVEL);

    /* Try to initialize SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    /* To use OpenGL legacy functions */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

    SDL_Window* window = create_window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!initGL())
    {
        printf("Unable to initialize OpenGL\n");
        exit(EXIT_FAILURE);
    }
    set_background_color(BACKGROUND_COLOR);

    engine_timer_t animation_timer = create_timer(0.3);
    start_timer(&animation_timer);

    engine_timer_t fps_timer = create_timer(1);
    start_timer(&fps_timer);

    // The division is to the get the time in seconds, not in miliseconds
    float actual_frame = SDL_GetTicks() / SECONDS_TO_MILLISECONDS(1);

    while (true)
    {
        float previous_frame = actual_frame;
        actual_frame = SDL_GetTicks() / SECONDS_TO_MILLISECONDS(1);
        delta_time = actual_frame - previous_frame;

        fps++;

        if (is_timer_up(&fps_timer))
        {
            printf("FPS: %i\n", fps);
            fps = 0;
            start_timer(&fps_timer);
        }

        if (is_timer_up(&animation_timer))
        {
            map_w[REAL_POS_TO_GRID_POS(3, 2)] = ((map_w[REAL_POS_TO_GRID_POS(3, 2)] + 1) % 3) + 1;
            start_timer(&animation_timer);
        }

        if (!handle_input()) // The window is closed
        {
            break;
        }
        move_player();

        glClear(GL_COLOR_BUFFER_BIT);
        render_screen();
        SDL_GL_SwapWindow(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    exit(EXIT_SUCCESS);
}
