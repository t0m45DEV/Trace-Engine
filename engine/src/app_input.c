#include "app_input.h"

#include "SDL_keyboard.h"
#include "SDL_scancode.h"

static bool previous_keyboard_state[SDL_NUM_SCANCODES] = {0};

bool is_key_being_pressed(char key)
{
    const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);
    
    return (keyboard_state[SDL_GetScancodeFromKey(key)] != 0);
}

bool is_key_just_pressed(char key)
{
    const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);

    bool is_pressed_now = (keyboard_state[SDL_GetScancodeFromKey(key)] != 0);

    bool is_just_pressed = is_pressed_now && !previous_keyboard_state[SDL_GetScancodeFromKey(key)];

    previous_keyboard_state[SDL_GetScancodeFromKey(key)] = is_pressed_now;

    return is_just_pressed;
}
