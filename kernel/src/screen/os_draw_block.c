#include <mikeos.h>

void _os_draw_block(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_draw_block(*bx & 0x00FF,
                *dx & 0x00FF,
                (*dx >> 8) & 0x0FF,
                *si,
                *di);
}

void os_draw_block(char color, char start_x, char start_y, char width, char end_y)
{
    
}
