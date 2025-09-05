#ifndef _H_DELTA_TIME
#define _H_DELTA_TIME

/**
 * A counter for delta time, the difference between every frame
 * 
 * @param actual_frame The total time elapsed, in miliseconds
 * @param last_frame The last registered frame, in miliseconds
 * @param delta_time The difference between actual_frame and last_frame
 */
typedef struct {
    float actual_frame; /**< Time of the current frame (the one being calculated) */
    float last_frame;   /**< Time of the last frame (the one being shown) */
    float delta_time;   /**< actual_frame - last_frame */
} delta_time_counter_t;

/**
 * Initialize everything to track delta_time
 */
void init_delta_time_counter(void);

/**
 * Update the current delta_time
 * 
 * @note This NEEDS to be called every frame, in the main loop
 */
void update_delta_time_counter(void);

/**
 * Returns the difference between the actual frame and the last one
 */
float get_delta_time(void);

#endif
