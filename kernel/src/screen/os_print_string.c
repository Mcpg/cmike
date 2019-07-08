#include <mikeos.h>

void _os_print_string(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_print_string((char*) *si);
}

void os_print_string(char* string)
{
    /* Potentially I could implement manual text buffer manipulation,
       which could possibly increase the performance */

    for (int i = 0; string[i]; i++)
    {
        asm volatile("int $0x10" : : "a" (0x0E00 | (string[i] & 0xFF)));
    }
}
