#ifndef _H_INPUT
#define _H_INPUT

#include "defines.h"
#include "window_display.h"
#include "trigonometry.h"
#include "player.h"
#include "world.h"

/* Action keys */

#define CHANGE_DEBUG_MODE_BUTTON SDL_GetScancodeFromKey('|') /**< To test new mechanics */

#define MOVE_FORWARD_BUTTON  SDL_GetScancodeFromKey('w')
#define MOVE_BACKWARD_BUTTON SDL_GetScancodeFromKey('s')
#define ROTATE_ANTI_CLOCKWISE_BUTTON SDL_GetScancodeFromKey('a')
#define ROTATE_CLOCKWISE_BUTTON      SDL_GetScancodeFromKey('d')

#define OPEN_DOOR_BUTTON SDL_GetScancodeFromKey('e')


/**
 * State of the keys being pressed, used to press distinct keys simultaneously
 *
 * 1 means pressed, 0 means not
 */
typedef struct {
    int move_forward;          /**< The state of the key to move forward */
    int move_backward;         /**< The state of the key to move backward */
    int rotate_anti_clockwise; /**< The state of the key to rotate anti clockwise */
    int rotate_clockwise;      /**< The state of the key to rotate clockwise */
} keys_state_t;

/** The current state of the keyboard */
extern keys_state_t action_keys_state;

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