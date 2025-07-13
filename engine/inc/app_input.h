#ifndef _H_APP_INPUT
#define _H_APP_INPUT

#include <stdbool.h>

/**
 * Returns true if the given key is being pressed
 */
bool is_key_being_pressed(char key);

/**
 * Returns true when the key has just been pressed
 */
bool is_key_just_pressed(char key);

#endif
