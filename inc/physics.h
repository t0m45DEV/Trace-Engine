#ifndef _H_PHYSICS
#define _H_PHYSICS

#include "player.h"

extern float delta_time;   /**< The time elapsed between last frame and the actual one */

/**
 * Handle the world physics: player movement, collision detection, pathfinding, etc
 */
void handle_physics(void);

#endif
