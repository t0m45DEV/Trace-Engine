#include "log.h"
#include "app_input.h"

/**
 * This is where the first things you want to happen in your game
 * should be: initialize structures, maps, players, do your mallocs,
 * everything that happen only once and at the start of the game
 * should be here
 */
void init_game(void);

/**
 * This function is called every frame, so if you want some structure
 * to update, or get a current key state, or redraw the window to show
 * a menu, should be here
 * 
 * @note If something updates position (like the player or an entity) you also
 * should multiply that distance by delta_time (the difference in time
 * between the last frame and the current one)
 */
void update_game(float delta_time);

/**
 * This is the last called function before closing the window and all
 * that, here you should put free if you called a malloc or save files
 */
void close_game(void);
