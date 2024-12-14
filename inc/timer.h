#ifndef _H_TIMER
#define _H_TIMER

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define SECONDS_TO_MILISECONDS(X) ((X) * 1000.0)
#define MILISECONDS_TO_SECONDS(X) ((X) / 1000.0)

/**
 * A timer struct, can init and check when is stopped
 */
typedef struct {
    bool is_active;     /**< False means the timer is stopped, true means the timer is running */
    float duration;     /**< The timer duration in miliseconds */
    float initial_time; /**< The timer activation time, in miliseconds */
} engine_timer_t;

/**
 * Only for debug, it shows the timer info
 */
void print_timer(engine_timer_t* timer);

/**
 * Creates a timer object with the duration (in seconds) passed by argument
 *
 * @note It does NOT start running!
 */
engine_timer_t create_timer(float duration);

/**
 * Starts the given timer
 */
void start_timer(engine_timer_t* timer);

/**
 * Sets the timer to not running
 */
void reset_timer(engine_timer_t* timer);

/**
 * Returns true if the timer stops, returns false if not
 *
 * @note If the timer is inactive, the function will always return true (inactive is equal to stopped)
 */
bool is_timer_up(engine_timer_t* timer);

#endif