#include <mikeos.h>

void _os_print_newline(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_newline();
}

void os_print_newline()
{
    os_print_string("\n");
}
