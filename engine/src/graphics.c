#include "graphics.h"

#include "glad/glad.h"
#include "game_state.h"
#include "raycaster.h"
#include "player.h"
#include "pop_up_windows.h"

resolutions_t resolution = LOW_RESOLUTION;

int get_actual_resolution(void)
{
    return resolution;
}

void set_actual_resolution(resolutions_t new_resolution)
{
    resolution = new_resolution;
}

void set_background_color(const rgb_t color)
{
    glClearColor(color.r, color.g, color.b, 1);
}

void render_screen(void)
{
    switch (get_current_scene())
    {
        case MAIN_MENU_SCENE:
            break;
        
        case GAME_SCENE:
            if (is_top_down_view_on()) draw_map_2D();
            cast_rays();
            if (is_top_down_view_on()) draw_player();
            break;

        default:
            break;
    }
    if (is_debug_console_on())
    {
        show_debug_console();
    }
}

void draw_square(position_2D_t position, position_2D_t size, int border, rgb_t color)
{
    glColor3ub(color.r, color.g, color.b);

    glBegin(GL_QUADS);
        glVertex2i(position.x          + border, position.y          + border);
        glVertex2i(position.x          + border, position.y + size.y - border);
        glVertex2i(position.x + size.x - border, position.y + size.y - border);
        glVertex2i(position.x + size.x - border, position.y          + border);
    glEnd();
}

void draw_point(position_2D_t position, int size, rgb_t color)
{
    glColor3ub(color.r, color.g, color.b);
    glPointSize(size);

    glBegin(GL_POINTS);
        glVertex2i(position.x, position.y);
    glEnd();
}

void draw_line(position_2D_t start_point, position_2D_t end_point, int thickness, rgb_t color)
{
    glColor3ub(color.r, color.g, color.b);
    glLineWidth(thickness);

    glBegin(GL_LINES);
        glVertex2i(start_point.x, start_point.y);
        glVertex2i(end_point.x, end_point.y);
    glEnd();
}

