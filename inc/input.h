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


typedef struct {
    int move_forward;
    int move_backward;
    int rotate_left;
    int rotate_right;
} keys_state_t;

extern keys_state_t action_keys_state;


void move_player(void);

/*
    If the key being pressed is an action key, we update the game state to respond

    @param key The key being pressed
    @param x
    @param y
*/
void buttons_down(unsigned char key, int x, int y);
void buttons_up(unsigned char key, int x, int y);

#endif