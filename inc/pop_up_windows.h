#ifndef _H_POP_UP_WIN
#define _H_POP_UP_WIN

#include <SDL.h>
#include <SDL_opengl.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#include "nuklear/nuklear.h"

#if defined(__EMSCRIPTEN__) // If the game will run in the web
    #include "nuklear/nuklear_sdl_gles2.h"
#else // If the game will run locally
    #include "nuklear/nuklear_sdl_gl2.h"
#endif

#include "loop.h"
#include "defines.h"

extern struct nk_context* nk_ctx; /** The context for Nuklear, it is necessary to create all the windows */

/**
 * Initialize everything for the Nuklear windows (like themes)
 */
void init_nk_windows(struct nk_context* context);

/**
 * It creates the debug console, from which you can access all the data and info of the engine
 */
void show_debug_console(void);

#endif
