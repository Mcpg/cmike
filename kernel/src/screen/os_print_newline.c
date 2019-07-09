#include <mikeos.h>

void _os_print_newline(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_newline(DEFAULT_COLOR);
}

void os_print_newline(char color)
{
    os_print_string("\n", DEFAULT_COLOR);
}
