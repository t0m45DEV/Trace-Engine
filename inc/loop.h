#ifndef _H_LOOP
#define _H_LOOP

#include <GL/gl.h>

#include "window_display.h"
#include "world.h"
#include "physics.h"
#include "timer.h"

typedef struct {
    float actual_frame;
    float last_frame;
    int fps;
    engine_timer_t* timer;
} FPS_counter_t;

extern FPS_counter_t FPS_counter;

void main_loop(void);

#endif
