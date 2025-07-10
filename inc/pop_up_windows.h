#ifndef _H_POP_UP_WIN
#define _H_POP_UP_WIN

#include "SDL.h"
#include "SDL_opengl.h"

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#include "Nuklear/nuklear.h"
#include "Nuklear/demo/sdl_opengl2/nuklear_sdl_gl2.h"

#define FPS_IN_CHART 33 /** How many last FPS to show in the performance graph, think of it as a FPS history count */

extern struct nk_context* nk_ctx; /** The context for Nuklear, it is necessary to create all the windows */

/**
 * Update the current FPS history, you can see the chart in the debug window
 */
void update_fps_history(void);

/**
 * Initialize everything for the Nuklear windows (like themes)
 */
void init_nk_windows(struct nk_context* context);

/**
 * It creates the debug console, from which you can access all the data and info of the engine
 */
void show_debug_console(void);

#endif
