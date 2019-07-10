#include <mikeos.h>

#define TOPBOT_COLOR COLOR_CREATE(COLOR_BLACK, COLOR_LIGHT_GRAY)

void _os_draw_background(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_draw_background((char*) *ax, (char*) *bx, *cx);
}

void os_draw_background(char* top, char* bottom, int color)
{
    os_clear_screen();
    os_draw_block(color, 0, 0, 80, 24);
    os_draw_block(TOPBOT_COLOR, 0, 24, 80, 24);
    os_draw_block(TOPBOT_COLOR, 0, 0, 80, 0);
    os_move_cursor(0, 1);
    os_print_string(top, TOPBOT_COLOR);
    os_move_cursor(24, 1);
    os_print_string(bottom, TOPBOT_COLOR);
}
