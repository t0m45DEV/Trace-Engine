#include <stdlib.h>
#include <stdbool.h>

/** The title to be shown on the top of the window */
#define WINDOW_TITLE "Tom's 3D Engine"

#define WINDOW_HEIGHT (VIEWPORT_HEIGHT + (VIEWPORT_Y_OFFSET * 2))
#define WINDOW_WIDTH  (VIEWPORT_WIDTH + (VIEWPORT_X_OFFSET * 2))

#include "Tom_Engine.h"

#include "log.h"
#include "raycaster.h"
#include "window_manager.h"
#include "game_state.h"
#include "delta_time.h"
#include "fps_counter.h"
#include "map.h"
#include "textures.h"
#include "basic_input.h"
#include "pop_up_windows.h"
#include "physics.h"

int main(void)
{
    log_info("Welcome to Tom's 3D Engine.");
    load_textures();

    init_game_state();
    load_level(FIRST_LEVEL);
    
    create_window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    init_raycaster();
    init_delta_time_counter();
    init_fps_counter();

    init_game();

    while (is_game_running())
    {
        update_delta_time_counter();
        update_fps_counter();
        update_fps_history();

        handle_input();
        handle_physics(get_delta_time());

        update_window();

        update_game(get_delta_time());

        swap_window_buffers();
    }
    quit_raycaster();
    destroy_window();
    log_info("Good bye :)");

    close_game();

    exit(EXIT_SUCCESS);
}
