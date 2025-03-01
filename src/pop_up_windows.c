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
    if (nk_begin(nk_ctx, "Demo", nk_rect(50, 50, 200, 200),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
        NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        nk_menubar_begin(nk_ctx);
        nk_layout_row_begin(nk_ctx, NK_STATIC, 25, 2);
        nk_layout_row_push(nk_ctx, 45);
        if (nk_menu_begin_label(nk_ctx, "FILE", NK_TEXT_LEFT, nk_vec2(120, 200))) {
            nk_layout_row_dynamic(nk_ctx, 30, 1);
            nk_menu_item_label(nk_ctx, "OPEN", NK_TEXT_LEFT);
            nk_menu_item_label(nk_ctx, "CLOSE", NK_TEXT_LEFT);
            nk_menu_end(nk_ctx);
        }
        nk_layout_row_push(nk_ctx, 45);
        if (nk_menu_begin_label(nk_ctx, "EDIT", NK_TEXT_LEFT, nk_vec2(120, 200))) {
            nk_layout_row_dynamic(nk_ctx, 30, 1);
            nk_menu_item_label(nk_ctx, "COPY", NK_TEXT_LEFT);
            nk_menu_item_label(nk_ctx, "CUT", NK_TEXT_LEFT);
            nk_menu_item_label(nk_ctx, "PASTE", NK_TEXT_LEFT);
            nk_menu_end(nk_ctx);
        }
        nk_layout_row_end(nk_ctx);
        nk_menubar_end(nk_ctx);

        {
            enum {EASY, HARD};
            static int op = EASY;
            static int property = 20;
            nk_layout_row_static(nk_ctx, 30, 80, 1);
            if (nk_button_label(nk_ctx, "button"))
                printf("button pressed\n");
             nk_layout_row_dynamic(nk_ctx, 30, 2);
             if (nk_option_label(nk_ctx, "easy", op == EASY)) op = EASY;
             if (nk_option_label(nk_ctx, "hard", op == HARD)) op = HARD;
             nk_layout_row_dynamic(nk_ctx, 25, 1);
             nk_property_int(nk_ctx, "Compression:", 0, &property, 100, 10, 1);
        }
    }
    nk_end(nk_ctx);
}
