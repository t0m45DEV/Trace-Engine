#ifndef _H_WIN_DISP
#define _H_WIN_DISP

#include <GL/glut.h>

#define WINDOW_TITLE "Scape game"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define X_CENTER_POS ((glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2)
#define Y_CENTER_POS ((glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2)

void window_create(int argc, char** argv);

#endif