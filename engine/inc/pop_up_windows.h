#ifndef _H_POP_UP_WIN
#define _H_POP_UP_WIN

#include "SDL_events.h"

/**
 * Nuklear needs to start seeing mouse and keyboard input, call it every frame
 */
void start_nk_input_hanlder(void);

/**
 * Nuklear hanlder for an SDL_Event, call it every frame
 */
void run_nk_input_hanlder(SDL_Event* event);

/**
 * Nuklear needs to stop seeing mouse and keyboard input, call it every frame
 */
void stop_nk_input_hanlder(void);

/**
 * Update the current FPS history, you can see the chart in the debug window
 */
void update_fps_history(void);

/**
 * Initialize everything for the Nuklear windows (like themes)
 */
void init_nk_windows(SDL_Window* current_window);

/**
 * Close all Nuklear functionality
 */
void close_nk(void);

/**
 * It creates the debug console, from which you can access all the data and info of the engine
 */
void show_debug_console(void);

// ===========================
// === Nuklear Themes Stuff
// ===========================

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

/**
 * Sets the given theme to the floating windows, sliders, buttons and stuff
 */
void set_style(nk_theme_t theme);

#endif
