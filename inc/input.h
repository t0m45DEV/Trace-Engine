#ifndef _H_INPUT
#define _H_INPUT

#include "window_display.h"
#include "trigonometry.h"
#include "player.h"
#include "world.h"

/* Action keys */

#define CHANGE_DEBUG_MODE SDL_GetScancodeFromKey('|') /* To test new mechanics */

#define MOVE_FORWARD  SDL_GetScancodeFromKey('w')
#define MOVE_BACKWARD SDL_GetScancodeFromKey('s')
#define ROTATE_ANTI_CLOCKWISE SDL_GetScancodeFromKey('a')
#define ROTATE_CLOCKWISE      SDL_GetScancodeFromKey('d')


/*
    State of the keys being pressed

    1 means pressed, 0 means not
*/
typedef struct keys_state_s {
    int move_forward;
    int move_backward;
    int rotate_anti_clockwise;
    int rotate_clockwise;
} keys_state_t;

/* The current state of the keyboard */
extern keys_state_t action_keys_state;

/*
    Move the player using the info in the player struct from player.h and the action_key_state struct from input.h
*/
void move_player(void);

/*
    Handle user input, return 0 if the detected event is closing the window, 1 otherwise
*/
bool handle_input(void);

/*
    Given an SDL_Event, it returns the keyboard key scancode that matches that event
*/
SDL_Scancode get_scancode(SDL_Event event);

#endif