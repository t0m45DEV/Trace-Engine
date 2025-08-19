#ifndef _H_BASIC_INPUT
#define _H_BASIC_INPUT

#include "SDL_events.h"
#include <stdbool.h>

/**
 * Handle user input
 */
void handle_input(void);

/**
 * Given an SDL_Event, it returns the keyboard key scancode that matches that event
 *
 * @param event SDL_Event, an event type from SDL
 */
SDL_Scancode get_scancode(const SDL_Event event);

#endif
