#ifndef _H_INPUT
#define _H_INPUT

#include "SDL_events.h"
#include "defines.h"

/**
 * Returns the current state of the action keys
 */
keys_state_t get_keys_state(void);

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