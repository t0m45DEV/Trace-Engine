#ifndef _H_NUKLEAR_STYLES
#define _H_NUKLEAR_STYLES

#include "pop_up_windows.h"

#define THEME_COUNT 10

typedef enum {
    THEME_BLACK,
    THEME_WHITE,
    THEME_RED,
    THEME_BLUE,
    THEME_DARK,
    THEME_DRACULA,
    THEME_CATPPUCCIN_LATTE,
    THEME_CATPPUCCIN_FRAPPE,
    THEME_CATPPUCCIN_MACCHIATO,
    THEME_CATPPUCCIN_MOCHA    
} nk_theme_t;

extern const char* themes_names[THEME_COUNT];

extern nk_theme_t current_theme;

void set_style(struct nk_context *ctx, nk_theme_t theme);

#endif