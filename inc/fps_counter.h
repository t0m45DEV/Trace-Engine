#ifndef _H_FPS_COUNTER
#define _H_FPS_COUNTER

#include "physics.h"
#include "timer.h"

/**
 * Initialize the everything to count the frames of the engine per second
 */
void init_fps_counter(void);

/**
 * Update the current counter for the FPS
 * 
 * @note This NEEDS to be called every frame, in the main loop
 */
void update_fps_counter(void);

#endif
