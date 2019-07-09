#include <mikeos.h>

char* digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void _os_print_1hex(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_1hex(*ax & 0x00FF, DEFAULT_COLOR);
}

void os_print_1hex(char number, char color)
{
    cmike_print_char(digits[number & 0x0F], color);
}
