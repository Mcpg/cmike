#include <mikeos.h>

void _os_draw_background(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_draw_background((char*) *ax, (char*) *bx, *cx);
}

void os_draw_background(char* top, char* bottom, int color)
{
    
}
