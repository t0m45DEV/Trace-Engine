#ifndef _H_DELTA_TIME
#define _H_DELTA_TIME

#include <SDL.h>

#include "timer.h"

typedef struct {
    float actual_frame;
    float last_frame;
    float delta_time;
} delta_time_counter_t;

void init_delta_time_counter(void);

void update_delta_time_counter(void);

float get_delta_time(void);

#endif
