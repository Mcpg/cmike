#include <mikeos.h>

void _os_dump_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_dump_string((char*) *si, DEFAULT_COLOR);
}

void os_dump_string(char* string, char color)
{
    for (int i = 0; string[i]; i++)
    {
        os_print_2hex(string[i], color);
        os_print_space(color);
    }
    os_print_newline(color);
    os_print_newline(color);
    os_print_string(string, color);
    os_print_newline(color);
    os_print_newline(color);
}
