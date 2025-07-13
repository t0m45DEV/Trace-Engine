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
#include "loop.h"
#include "fps_counter.h"
#include "map.h"
#include "textures.h"

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
        main_loop();
        update_game(get_delta_time());
    }
    quit_raycaster();
    destroy_window();
    log_info("Good bye :)");

    close_game();

    exit(EXIT_SUCCESS);
}
