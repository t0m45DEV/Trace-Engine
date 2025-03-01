#define NK_IMPLEMENTATION

#if defined(__EMSCRIPTEN__) // If the game will run in the web
    #define NK_SDL_GLES2_IMPLEMENTATION
#else // If the game will run locally
    #define NK_SDL_GL2_IMPLEMENTATION
#endif

#include "pop_up_windows.h"

struct nk_context* nk_ctx = NULL;

void test_nk(void)
{
    /* GUI */
    if (nk_begin(nk_ctx, "Debug Console", nk_rect(50, 50, 200, 80),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|
        NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        {
            char fps_text[10];
            snprintf(fps_text, 10, "FPS: %i", game_state.fps);

            nk_layout_row_dynamic(nk_ctx, 20, 1);
            nk_label(nk_ctx, fps_text, NK_TEXT_LEFT);
        }
    }
    nk_end(nk_ctx);
}
