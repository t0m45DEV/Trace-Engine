#include "basic_input.h"

#include "game_state.h"
#include "pop_up_windows.h"
#include "player.h"

/* Action keys */

#define OPEN_DEBUG_WINDOW_BUTTON SDL_GetScancodeFromKey('|')

#define MOVE_FORWARD_BUTTON          SDL_GetScancodeFromKey('w')
#define MOVE_BACKWARD_BUTTON         SDL_GetScancodeFromKey('s')
#define ROTATE_ANTI_CLOCKWISE_BUTTON SDL_GetScancodeFromKey('a')
#define ROTATE_CLOCKWISE_BUTTON      SDL_GetScancodeFromKey('d')

#define OPEN_DOOR_BUTTON SDL_GetScancodeFromKey('e')

/** The current state of the keyboard */
keys_state_t action_keys_state = {0};

keys_state_t get_keys_state(void)
{
    return action_keys_state;
}

void handle_input(void)
{
    SDL_Event event;

    if (is_debug_console_on()) start_nk_input_hanlder();

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) // If the window closes
        {
            stop_game();
        }
        if (is_debug_console_on()) run_nk_input_hanlder(&event);

        // Simple input
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
        {
            if (get_scancode(event) == OPEN_DEBUG_WINDOW_BUTTON)
            {
                update_debug_console_state();
            }
            if (get_scancode(event) == OPEN_DOOR_BUTTON)
            {
                open_door();
            }
        }
    }
    // Simultaneous input
    SDL_PumpEvents();
    const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);

    action_keys_state.move_forward = (keyboard_state[MOVE_FORWARD_BUTTON] != 0);
    action_keys_state.move_backward = (keyboard_state[MOVE_BACKWARD_BUTTON] != 0);
    action_keys_state.rotate_anti_clockwise = (keyboard_state[ROTATE_ANTI_CLOCKWISE_BUTTON] != 0);
    action_keys_state.rotate_clockwise = (keyboard_state[ROTATE_CLOCKWISE_BUTTON] != 0);

    if (is_debug_console_on()) stop_nk_input_hanlder();
}

SDL_Scancode get_scancode(const SDL_Event event)
{
    return event.key.keysym.scancode;
}
