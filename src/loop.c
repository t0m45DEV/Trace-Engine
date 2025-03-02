#include "loop.h"

void main_loop(void)
{
    update_fps_counter();

    handle_input();
    handle_physics();

    glClear(GL_COLOR_BUFFER_BIT);
    render_screen();
    SDL_GL_SwapWindow(window);
}
