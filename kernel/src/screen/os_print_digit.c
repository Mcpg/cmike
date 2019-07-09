#include <mikeos.h>

void _os_print_digit(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_digit(*ax, DEFAULT_COLOR);
}

void os_print_digit(int digit, char color)
{
    cmike_print_char(digits[digit % 36], color);
}
