#define NK_IMPLEMENTATION

#if defined(__EMSCRIPTEN__) // If the game will run in the web
    #define NK_SDL_GLES2_IMPLEMENTATION
#else // If the game will run locally
    #define NK_SDL_GL2_IMPLEMENTATION
#endif

#include "pop_up_windows.h"
#include "nk_styles/nuklear_styles.c"

struct nk_context* nk_ctx = NULL;

void init_nk_windows(struct nk_context* context)
{
    set_style(context, current_theme);
}

void show_debug_console(void)
{
    /* GUI */
    if (nk_begin(nk_ctx, "Debug Console", nk_rect(50, 50, 200, 160),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|
        NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        nk_layout_row_dynamic(nk_ctx, 0, 2);
        {
            nk_theme_t new_theme;
            nk_label(nk_ctx, "Style:", NK_TEXT_LEFT);
            new_theme = nk_combo(nk_ctx, themes_names, NK_LEN(themes_names), current_theme, 25, nk_vec2(200, 200));
            if (new_theme != current_theme) {
                current_theme = new_theme;
                set_style(nk_ctx, current_theme);
            }
        }

        {
            char fps_text[10];
            snprintf(fps_text, 10, "FPS: %i", get_fps());

            nk_layout_row_dynamic(nk_ctx, 20, 1);
            nk_label(nk_ctx, fps_text, NK_TEXT_LEFT);

            nk_checkbox_label(nk_ctx, "Top view", &get_game_state()->is_on_debug_view_mode);

            if (nk_button_label(nk_ctx, "Reset level")) reload_level();
        }
    }
    nk_end(nk_ctx);
}
