#include "delta_time.h"

#include "timer.h"

// The counter for delta_time
delta_time_counter_t delta_t_ctr = {0};

void init_delta_time_counter(void)
{
    delta_t_ctr.actual_frame = get_actual_time_seconds();
}

void update_delta_time_counter(void)
{
    delta_t_ctr.last_frame = delta_t_ctr.actual_frame;
    delta_t_ctr.actual_frame = get_actual_time_seconds();
    delta_t_ctr.delta_time = delta_t_ctr.actual_frame - delta_t_ctr.last_frame;
}

float get_delta_time(void)
{
    return delta_t_ctr.delta_time;
}
