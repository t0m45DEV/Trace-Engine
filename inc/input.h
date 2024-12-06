#ifndef _H_INPUT
#define _H_INPUT

#include "window_display.h"
#include "trigonometry.h"
#include "player.h"
#include "world.h"

/* Action keys */

#define CHANGE_DEBUG_MODE '|' /* To test new mechanics */

#define MOVE_FORWARD  'w'
#define MOVE_BACKWARD 's'
#define ROTATE_ANTI_CLOCKWISE 'a'
#define ROTATE_CLOCKWISE      'd'


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
    If the key being pressed is an action key, we set the corresponding state of action_keys_state to 1
*/
void button_down(char key);

/*
    If the key being pressed is an action key, we set the corresponding state of action_keys_state to 0
*/
void button_up(char key);

/*
    Check if event is a key pressed type event and, if it is, do what that input does
*/
void handle_input(SDL_Event event);

/*
    Given an event, return the char of the key assign to it
*/
char get_key(SDL_Event event);

#endif