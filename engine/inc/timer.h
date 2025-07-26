#ifndef _H_TIMER
#define _H_TIMER

#include <stdbool.h>

/**
 * A timer struct, can init and check when is stopped
 */
typedef struct {
    bool is_active;     /** False means the timer is stopped, true means the timer is running */
    float duration;     /** The timer duration in miliseconds */
    float initial_time; /** The timer activation time, in miliseconds */
} engine_timer_t;

#ifndef GAME_EXPORT
    /**
     * @note Remember to free the memory allocated for the string!
     */
    #define timer_to_string(X) timer_to_string_with_name(X, #X)

    /**
     * Only for debug, it returns the timer in the form of a string
     * 
     * @param timer engine_timer_t, the timer to print
     * 
     * @note Caller MUST free the memory allocated for the string
     */
    char* timer_to_string_with_name(const engine_timer_t timer, const char* timer_name);
#else
    #define debug_position(X) // Does nothing
#endif

/**
 * Returns the ticks elapsed in seconds
 */
float get_actual_time_seconds(void);

/**
 * Returns the ticks elapsed in milliseconds
 */
float get_actual_time_milliseconds(void);

/**
 * Only for debug, it shows the timer info
 * 
 * @param timer A pointer to the timer to print
 */
void print_timer(const engine_timer_t* timer);

/**
 * Creates a timer object with the duration (in seconds) passed by argument
 *
 * @note It does NOT start running!
 * 
 * @param duration The duration (in seconds) that the timer will save
 */
engine_timer_t create_timer(const float duration);

/**
 * Starts the given timer
 * 
 * @param timer A pointer to the timer to start
 */
void start_timer(engine_timer_t* timer);

/**
 * Sets the timer to not running
 * 
 * @param timer A pointer to the timer to reset
 */
void reset_timer(engine_timer_t* timer);

/**
 * Returns true if the timer stops and call reset_timer with the given timer; returns false if the timer has yet not finished
 *
 * @note If the timer is inactive, the function will always return false (inactive is equal to running)
 * 
 * @param timer A pointer to the timer to check
 */
bool is_timer_up(engine_timer_t* timer);

#endif