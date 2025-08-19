#include "basic_input.h"

#include "game_state.h"
#include "pop_up_windows.h"

/* Action keys */

#define OPEN_DEBUG_WINDOW_BUTTON SDL_GetScancodeFromKey('|')

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
        }
    }
    // Simultaneous input
    SDL_PumpEvents();

    if (is_debug_console_on()) stop_nk_input_hanlder();
}

SDL_Scancode get_scancode(const SDL_Event event)
{
    return event.key.keysym.scancode;
}
