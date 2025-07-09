#include "loop.h"

#include "pop_up_windows.h"
#include "window_display.h"
#include "delta_time.h"
#include "physics.h"
#include "fps_counter.h"
#include "input.h"

#include "SDL2/include/SDL_video.h"

void main_loop(SDL_Window* window)
{
    update_delta_time_counter();
    update_fps_counter();
    update_fps_history();

    handle_input();
    handle_physics(get_delta_time());

    glClear(GL_COLOR_BUFFER_BIT);
    render_screen();
    SDL_GL_SwapWindow(window);
}
