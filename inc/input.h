#ifndef _H_INPUT
#define _H_INPUT


// Action keys

#define MOVE_FORWARD  'w'
#define MOVE_BACKWARD 's'
#define ROTATE_LEFT   'a'
#define ROTATE_RIGHT  'd'


/*
    If the key being pressed is an action key, we update the game state to respond

    @param key The key being pressed
    @param x
    @param y
*/
void buttons(unsigned char key, int x, int y);

#endif