#include "timer.h"
#include "SDL2/include/SDL_timer.h"

#define SECONDS_TO_MILLISECONDS(X) ((X) * 1000.0)
#define MILLISECONDS_TO_SECONDS(X) ((X) / 1000.0)

#ifndef GAME_EXPORT
    #include <stdio.h>
    #include <stdlib.h>
    #include "log.h"

    char* timer_to_string_with_name(const engine_timer_t timer, const char* timer_name)
    {
        const int MAX_LEN = 300;
        char* string = malloc(sizeof(char) * MAX_LEN);

        const char* timer_parsed = 
            "\n\t=== Timer %s ===\n"
            "\t\tIs active: %i\n"
            "\t\tDuration: %f ms\n"
            "\t\tInitial time: %f ms\n"
        ;

        int printf_out = snprintf(string, MAX_LEN, timer_parsed,
            timer_name, timer.is_active, timer.duration, timer.initial_time
        );

        if (printf_out <= 0)
        {
            log_error("There was an error parsing to string for %s", timer_name);
        }
        return string;
    }
#endif

float get_actual_time_seconds(void)
{
    return SDL_GetTicks() / SECONDS_TO_MILLISECONDS(1);
}

float get_actual_time_milliseconds(void)
{
    return SDL_GetTicks();
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
