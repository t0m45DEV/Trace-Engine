#include "timer.h"
#include <SDL_timer.h>

#define SECONDS_TO_MILLISECONDS(X) ((X) * 1000.0)
#define MILLISECONDS_TO_SECONDS(X) ((X) / 1000.0)

float get_actual_time_seconds(void)
{
    return SDL_GetTicks() / MILLISECONDS_TO_SECONDS(1);
}

float get_actual_time_milliseconds(void)
{
    return SDL_GetTicks();
}

void print_timer(const engine_timer_t* timer)
{
    printf("Is active: %i\n", timer->is_active);
    printf("Duration: %f\n", timer->duration);
    printf("Initial time: %f\n", timer->initial_time);
}

engine_timer_t create_timer(const float duration)
{
    engine_timer_t timer;
    timer.is_active = false;
    timer.duration = SECONDS_TO_MILLISECONDS(duration);
    timer.initial_time = 0;
    return timer;
}

void start_timer(engine_timer_t* timer)
{
    timer->is_active = true;
    timer->initial_time = SDL_GetTicks();
}

void reset_timer(engine_timer_t* timer)
{
    *timer = create_timer(MILLISECONDS_TO_SECONDS(timer->duration));
}

bool is_timer_up(engine_timer_t* timer)
{
    if (!timer->is_active)
    {
        return false;
    }
    float actual_time = SDL_GetTicks();

    if ((actual_time - timer->initial_time) >= timer->duration)
    {
        reset_timer(timer);
        return true;
    }
    return false;
}
