#include <mikeos.h>

void _os_draw_block(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_draw_block(*bx & 0x00FF,
                *dx & 0x00FF,
                (*dx >> 8) & 0x0FF,
                *si,
                *di);
}

/* end_y is the Y at which the loop will end. Block line will NOT be drawn
   at end_y */
void os_draw_block(char color, char start_x, char start_y, char width, char end_y)
{
    for (int y = start_y; y < end_y; y++)
    {
        os_move_cursor(y, start_x);
        asm("int $0x10" : : "a" (0x0900 | ' '), "b" (color & 0x00FF), "c" (width & 0x00FF));
    }
}
