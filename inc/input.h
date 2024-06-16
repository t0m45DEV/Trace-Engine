#ifndef _H_INPUT
#define _H_INPUT

#include "window_display.h"
#include "trigonometry.h"
#include "player.h"

// Action keys

#define CHANGE_DEBUG_MODE '|'

#define MOVE_FORWARD  'w'
#define MOVE_BACKWARD 's'
#define ROTATE_LEFT   'a'
#define ROTATE_RIGHT  'd'


/*
    State of the keys being pressed

    1 means pressed, 0 means not
*/
typedef struct keys_state_s {
    int move_forward;
    int move_backward;
    int rotate_left;
    int rotate_right;
} keys_state_t;

extern keys_state_t action_keys_state;


/*
    Move the player using the info in the player struct from player.h and the action_key_state struct from input.h
*/
void move_player(void);


/*
    If the key being pressed is an action key, we set the corresponding state of action_keys_state to 1
*/
void buttons_down(unsigned char key, int x, int y);

/*
    If the key being pressed is an action key, we set the corresponding state of action_keys_state to 0
*/
void buttons_up(unsigned char key, int x, int y);

#endif