#include <mikeos.h>

void _os_print_horiz_line(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_horiz_line(*ax, DEFAULT_COLOR);
}

void os_print_horiz_line(int line_type, char color)
{
    
    char type = 196;
    if (line_type == SCREEN_LINE_DOUBLE)
    {
        type = 205;
    }
    for (int i = 0; i < 80; i++)
    {
        cmike_print_char(type, color);
    }
}
