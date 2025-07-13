#include "loop.h"

#include "pop_up_windows.h"
#include "delta_time.h"
#include "physics.h"
#include "fps_counter.h"
#include "basic_input.h"
#include "window_manager.h"


void main_loop(void)
{
    update_delta_time_counter();
    update_fps_counter();
    update_fps_history();

    handle_input();
    handle_physics(get_delta_time());

    update_window();
}
