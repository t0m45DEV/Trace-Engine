#include "input.h"

keys_state_t action_keys_state = {0};

void handle_input(void)
{
    if (game_state.shows_debug_pop_up) nk_input_begin(nk_ctx);

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) // If the window closes
    {
        game_state.is_game_running = false;
    }
    if (game_state.shows_debug_pop_up) nk_sdl_handle_event(&event);

    // Simultaneous input
    SDL_PumpEvents();
    const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);

    action_keys_state.move_forward = (keyboard_state[MOVE_FORWARD_BUTTON] != 0);
    action_keys_state.move_backward = (keyboard_state[MOVE_BACKWARD_BUTTON] != 0);
    action_keys_state.rotate_anti_clockwise = (keyboard_state[ROTATE_ANTI_CLOCKWISE_BUTTON] != 0);
    action_keys_state.rotate_clockwise = (keyboard_state[ROTATE_CLOCKWISE_BUTTON] != 0);

    // Simple input
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        if (get_scancode(event) == CHANGE_DEBUG_MODE_BUTTON)
        {
            game_state.shows_debug_pop_up = !game_state.shows_debug_pop_up;
        }
        if (get_scancode(event) == OPEN_DOOR_BUTTON)
        {
            open_door();
        }
    }
    if (game_state.shows_debug_pop_up) nk_input_end(nk_ctx);
}

SDL_Scancode get_scancode(const SDL_Event event)
{
    return event.key.keysym.scancode;
}
