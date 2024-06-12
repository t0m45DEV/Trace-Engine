#ifndef _H_DEFINES
#define _H_DEFINES

#include <GL/glut.h>

//   Window parameters
// ==========================

#define WINDOW_TITLE "Scape game"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define X_CENTER_POS ((glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2)
#define Y_CENTER_POS ((glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2)


//   Player parameters
// ==========================

#define P_INIT_X_POS 300.0
#define P_INIT_Y_POS 300.0


#endif