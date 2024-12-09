#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "window_display.h"
#include "world.h"
#include "player.h"

bool initGL()
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

int main()
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

    // The division is to the get the time in seconds, not in miliseconds
    float actual_frame = SDL_GetTicks() / 1000.0;

    while (true)
    {
        float previous_frame = actual_frame;
        actual_frame = SDL_GetTicks() / 1000.0;
        delta_time = actual_frame - previous_frame;

        if (!handle_input())
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
