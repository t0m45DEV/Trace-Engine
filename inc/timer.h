#ifndef _H_TIMER
#define _H_TIMER

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define SECONDS_TO_MILISECONDS(X) ((X) * 1000.0)
#define MILISECONDS_TO_SECONDS(X) ((X) / 1000.0)

/*
    A timer struct, can init and check when is stopped

    @param is_active int, false means the timer is stopped, true means the timer is running
    @param duration float, the timer duration in miliseconds
    @param initial_time, the timer activation time, in miliseconds
*/
typedef struct timer_s {
    bool is_active;
    float duration;
    float initial_time;
} engine_timer_t;

/*
    Only for debug, it shows the timer info
*/
void print_timer(engine_timer_t* timer);

/*
    Creates a timer object with the duration (in seconds) passed by argument

    It does not start running!
*/
engine_timer_t create_timer(float duration);

/*
    Starts the given timer
*/
void start_timer(engine_timer_t* timer);

/*
    Sets the timer to not running
*/
void reset_timer(engine_timer_t* timer);

/*
    Returns true if the timer stops, returns false if not
*/
bool is_timer_up(engine_timer_t* timer);

#endif