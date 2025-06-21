#include "pop_up_windows.h"
#include "nuklear/nuklear_styles.h"

#include "timer.h"
#include "game_state.h"

struct nk_context* nk_ctx = NULL;

engine_timer_t debug_fps_timer;
int last_fps[FPS_IN_CHART] = {0}; // FPS history

void update_fps_history(void)
{
    if (is_timer_up(&debug_fps_timer))
    {
        for (int i = 0; i < FPS_IN_CHART - 1; i++)
        {
            last_fps[i] = last_fps[i + 1];
        }
        last_fps[FPS_IN_CHART - 1] = get_fps();
        start_timer(&debug_fps_timer);
    }
}

void init_nk_windows(struct nk_context* context)
{
    debug_fps_timer = create_timer(1);
    start_timer(&debug_fps_timer);
    set_style(context, current_theme);

    // Load the default font for Nuklear
    struct nk_font_atlas *atlas;
    nk_sdl_font_stash_begin(&atlas);
    nk_sdl_font_stash_end();
}

void show_debug_console(void)
{
    /* GUI */
    if (nk_begin(nk_ctx, "Debug Console", nk_rect(50, 50, 190, 260),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|
        NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        if (nk_tree_push(nk_ctx, NK_TREE_TAB, "Window style", NK_MINIMIZED))
        {
            nk_layout_row_dynamic(nk_ctx, 0, 2);
            nk_theme_t new_theme;
            nk_label(nk_ctx, "Theme:", NK_TEXT_LEFT);
            new_theme = nk_combo(nk_ctx, themes_names, THEME_COUNT, current_theme, 25, nk_vec2(200, 200));
            if (new_theme != current_theme) {
                current_theme = new_theme;
                set_style(nk_ctx, current_theme);
            }
            nk_tree_pop(nk_ctx);
        }

        if (nk_tree_push(nk_ctx, NK_TREE_TAB, "Performance", NK_MINIMIZED))
        {
            nk_label(nk_ctx, "FPS:", NK_TEXT_LEFT);

            char fps_text[10];
            snprintf(fps_text, 10, "FPS: %i", get_fps());
            nk_layout_row_dynamic(nk_ctx, 20, 1);
            nk_label(nk_ctx, fps_text, NK_TEXT_LEFT);

            int index = -1;
            int past_fps = 0;

            nk_layout_row_dynamic(nk_ctx, 100, 1);
            nk_ctx->style.chart.show_markers = nk_true;
            if (nk_chart_begin(nk_ctx, NK_CHART_LINES, 32, 0, 120)) {

                for (int i = 0; i < FPS_IN_CHART; i++)
                {
                    nk_flags res = nk_chart_push(nk_ctx, (float) last_fps[i]);
                    
                    if (res & NK_CHART_HOVERING)
                    {
                        index = (int)i;
                        past_fps = last_fps[i];
                    }
                }
                nk_chart_end(nk_ctx);
            }
            if (index != -1) nk_tooltipf(nk_ctx, "FPS: %i", past_fps);

            nk_tree_pop(nk_ctx);
        }

        if (nk_tree_push(nk_ctx, NK_TREE_TAB, "Level design", NK_MINIMIZED))
        {
            nk_layout_row_dynamic(nk_ctx, 15, 1);

            nk_checkbox_label(nk_ctx, "Top view", &get_game_state()->is_on_debug_view_mode);

            if (nk_button_label(nk_ctx, "Reset level"))
            {
                reload_level();
            }
            nk_tree_pop(nk_ctx);
        }
    }
    nk_end(nk_ctx);
}
