#include "loop.h"

void main_loop(void)
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
