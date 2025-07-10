#ifndef _H_INPUT
#define _H_INPUT

#include "SDL2/include/SDL_events.h"

/**
 * State of the keys being pressed, used to press distinct keys simultaneously
 *
 * 1 means pressed, 0 means not
 */
typedef struct {
    int move_forward;          /** The state of the key to move forward */
    int move_backward;         /** The state of the key to move backward */
    int rotate_anti_clockwise; /** The state of the key to rotate anti clockwise */
    int rotate_clockwise;      /** The state of the key to rotate clockwise */
} keys_state_t;

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