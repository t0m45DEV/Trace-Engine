#include "fps_counter.h"

#include "game_state.h"
#include "timer.h"

/**
 * A little self-explanatory
 * 
 * @param actual_frame Is the current time (in ticks)
 * @param last_frame   Is the last saved time (in ticks)
 * @param fps          Current count of frames
 * @param timer        A timer of 1 second, after that it should resets back
 */
typedef struct {
    float actual_frame;
    float last_frame;
    int fps;
    trc_timer_t timer;
} FPS_counter_t;

FPS_counter_t FPS_counter = {0}; /** The struct that tracks current FPS */

void init_fps_counter(void)
{
    FPS_counter.timer = create_timer(1);
    start_timer(&FPS_counter.timer);

    // The division is to the get the time in seconds, not in miliseconds
    FPS_counter.actual_frame = get_actual_time_seconds();
}

void update_fps_counter(void)
{
    FPS_counter.last_frame = FPS_counter.actual_frame;
    FPS_counter.actual_frame = get_actual_time_seconds();

    FPS_counter.fps++;

    if (is_timer_up(&FPS_counter.timer))
    {
        update_game_state_fps(FPS_counter.fps);
        FPS_counter.fps = 0;
        start_timer(&FPS_counter.timer);
    }
}
