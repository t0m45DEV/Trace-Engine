#include "loop.h"

FPS_counter_t FPS_counter = {0};

void main_loop(void)
{
    FPS_counter.last_frame = FPS_counter.actual_frame;
    FPS_counter.actual_frame = SDL_GetTicks() / SECONDS_TO_MILLISECONDS(1);
    delta_time = FPS_counter.actual_frame - FPS_counter.last_frame;

    FPS_counter.fps++;

    if (is_timer_up(FPS_counter.timer))
    {
        game_state.fps = FPS_counter.fps;
        FPS_counter.fps = 0;
        start_timer(FPS_counter.timer);
    }

    handle_input();
    handle_physics();

    glClear(GL_COLOR_BUFFER_BIT);
    render_screen();
    SDL_GL_SwapWindow(window);
}
