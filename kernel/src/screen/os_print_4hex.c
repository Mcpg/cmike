#include <mikeos.h>

void _os_print_4hex(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_4hex(*ax, DEFAULT_COLOR);
}

void os_print_4hex(int number, char color)
{
    os_print_2hex((number >> 8) & 0xFF, color);
    os_print_2hex(number & 0xFF, color);
}
