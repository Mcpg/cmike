#include <mikeos.h>

void _os_print_2hex(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_2hex(*ax & 0x00FF, DEFAULT_COLOR);
}

void os_print_2hex(char number, char color)
{
    os_print_1hex(number >> 4, color);
    os_print_1hex(number & 0x0F, color);
}
