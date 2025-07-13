#ifndef _H_WIN_DISP
#define _H_WIN_DISP

/** Is good for the viewport size to satisfy WIDTH = HEIGHT * 1.5, and also for the numbers to be divisible by powers of 2 */

#define VIEWPORT_WIDTH  960
#define VIEWPORT_HEIGHT 640

#define VIEWPORT_X_OFFSET 10
#define VIEWPORT_Y_OFFSET 10

/**
 * Creates the window and the context for OpenGL
 * 
 * @param title The title of the window, it'll show up in the upper section of the window
 * @param width The window width in pixels
 * @param height The window height in pixels
 */
void create_window(const char* title, const int width, const int height);

/**
 * Clears the previous frame and renders the next frame
 */
void update_window(void);

/**
 * Swaps the current frame with the one rendered, call it every time at the end of
 * the main loop (when everything has been drawn)
 */
void swap_window_buffers(void);

/**
 * Calls every deleter function for the graphical stuff
 */
void destroy_window(void);

#endif