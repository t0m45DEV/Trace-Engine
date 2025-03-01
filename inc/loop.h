#ifndef _H_LOOP
#define _H_LOOP

#include <GL/gl.h>

#include "window_display.h"
#include "world.h"
#include "physics.h"
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
    engine_timer_t* timer;
} FPS_counter_t;

extern FPS_counter_t FPS_counter; /** The struct that tracks current FPS */

/**
 * Main loop of the game, here we make magic!
 */
void main_loop(void);

#endif
