#ifndef _H_INPUT
#define _H_INPUT

#include "defines.h"
#include "window_display.h"
#include "trigonometry.h"
#include "world.h"
#include "pop_up_windows.h"

/* Action keys */

#define CHANGE_DEBUG_MODE_BUTTON SDL_GetScancodeFromKey('|') /** To test new mechanics */

#define MOVE_FORWARD_BUTTON  SDL_GetScancodeFromKey('w')
#define MOVE_BACKWARD_BUTTON SDL_GetScancodeFromKey('s')
#define ROTATE_ANTI_CLOCKWISE_BUTTON SDL_GetScancodeFromKey('a')
#define ROTATE_CLOCKWISE_BUTTON      SDL_GetScancodeFromKey('d')

#define OPEN_DOOR_BUTTON SDL_GetScancodeFromKey('e')

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