#include "input.h"

/** The current state of the keyboard */
keys_state_t action_keys_state = {0};

keys_state_t get_keys_state(void)
{
    return action_keys_state;
}

void handle_input(void)
{
    SDL_Event event;

    if (is_debug_console_on()) nk_input_begin(nk_ctx);

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) // If the window closes
        {
            stop_game();
        }
        if (is_debug_console_on()) nk_sdl_handle_event(&event);

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

    if (is_debug_console_on()) nk_input_end(nk_ctx);
}

SDL_Scancode get_scancode(const SDL_Event event)
{
    return event.key.keysym.scancode;
}
