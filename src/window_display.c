#include "window_display.h"

int resolution = LOW_RESOLUTION;

bool debug_2D_view = false;

float fps = MAX_FPS;

float previous_frame = 0;
float actual_frame;

void update_fps(void)
{
    actual_frame = glutGet(GLUT_ELAPSED_TIME);
    fps = (actual_frame - previous_frame);
    previous_frame = glutGet(GLUT_ELAPSED_TIME);

    if (fps > MAX_FPS) fps = MAX_FPS;
}


void display(void)
{
    update_fps();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    move_player();
    
    if (debug_2D_view) draw_map_2D();
    cast_rays(debug_2D_view);
    if (debug_2D_view) draw_player();
    
    glutSwapBuffers();
}


void resize(int x, int y)
{
    glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}


void window_create(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(X_CENTER_POS, Y_CENTER_POS);
    glutCreateWindow(WINDOW_TITLE);
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    glClearColor(0.5, 0.5, 0.5, 0);
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(buttons_down);
    glutKeyboardUpFunc(buttons_up);
    glutMainLoop();
}
