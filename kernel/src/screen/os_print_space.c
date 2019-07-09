#include <mikeos.h>

void _os_print_space(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_space(DEFAULT_COLOR);
}

void os_print_space(char color)
{
    os_print_string(" ", color);
}
